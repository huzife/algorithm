#include "type/type.h"

class Solution1 {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

// 反转相关的直接用 std::reverse，一样快的
class Solution2 {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
