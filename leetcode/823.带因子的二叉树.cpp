#include "type/type.h"

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = 0;
        vector<long long> dp(arr.size(), 1);
        for (int i = 0; i < dp.size(); i++) {
            int l = 0;
            int r = i - 1;
            while (l <= r) {
                long long ret = arr[l] * arr[r];
                if (ret > arr[i]) {
                    r--;
                } else if (ret < arr[i]) {
                    l++;
                } else {
                    if (l == r) {
                        dp[i] += dp[l] * dp[r];
                    } else {
                        dp[i] += dp[l] * dp[r] * 2;
                    }
                    l++;
                    r--;
                }
            }
            ans = (ans + dp[i]) % 1000000007;
        }

        return ans;
    }
};
