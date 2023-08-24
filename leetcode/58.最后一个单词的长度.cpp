/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.find_last_not_of(' ');
        return r - s.find_last_of(' ', r);
    }
};
// @lc code=end
