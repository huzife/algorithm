#include "type/type.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (auto i : nums) {
            if (i != val) {
                nums[slow++] = i;
            }
        }
        return slow;
    }
};
