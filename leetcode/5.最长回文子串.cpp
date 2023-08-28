#include "type/type.h"

// dp
class Solution1 {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2)
            return s;

        int max_len = 1;
        int begin = 1;

        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        for (int i = 2; i <= len; i++) {
            for (int left = 0; left < len; left++) {
                int right = left + i - 1;
                if (right >= len)
                    break;

                if (s[left] != s[right]) {
                    dp[left][right] = false;
                    continue;
                }


                dp[left][right] = i > 2 ? dp[left + 1][right - 1] : true;

                if (dp[left][right] && i > max_len) {
                    max_len = i;
                    begin = left;
                }
            }
        }

        return s.substr(begin, max_len);
    }
};

// Manacher
class Solution2 {
public:
    string longestPalindrome(string s) {
        string str = "#";
        str.reserve(2 * s.size() + 1);
        for (auto i : s) {
            str += (i);
            str += '#';
        }

        int max_len = 1;
        int begin = 0;

        vector<int> len(str.size());
        int right = -1;
        int p = -1;

        for (int i = 0; i < str.size(); i++) {
            int cur_len = 0;
            if (right > i) {
                cur_len = min(len[2 * p - i], right - i);
            }

            int l = i - cur_len - 1;
            int r = i + cur_len + 1;
            while (l >= 0 && r < str.size() && str[l] == str[r]) {
                l--;
                r++;
                cur_len++;
            }

            len[i] = cur_len;
            if (r - 1 > right) {
                right = r - 1;
                p = i;
            }

            if (cur_len > max_len) {
                max_len = cur_len;
                begin = p / 2 - max_len / 2;
            }
        }

        return s.substr(begin, max_len);
    }
};
