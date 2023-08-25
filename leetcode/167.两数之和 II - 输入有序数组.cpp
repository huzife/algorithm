#include "type/type.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int sum = numbers[left] + numbers[right];
        while (sum != target) {
            if (sum < target) {
                left++;
            }
            else {
                right--;
            }
            sum = numbers[left] + numbers[right];
        }

        return {left + 1, right + 1};
    }
};
