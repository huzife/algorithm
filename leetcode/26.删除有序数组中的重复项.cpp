#include "type/type.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for (auto i : nums) {
            if (nums[slow] != i) {
                nums[++slow] = i;
            }
        }
        return slow + 1;
    }
};
