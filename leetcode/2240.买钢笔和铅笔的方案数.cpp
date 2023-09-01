#include "type/type.h"

// 直接枚举, 时间复杂度 O(total / cost1)
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2) {
            swap(cost1, cost2);
        }
        int m = total / cost1;

        long long ans = 0;
        for (int i = 0; i <= m; i++) {
            ans += (total - i * cost1) / cost2 + 1;
        }
        return ans;
    }
};
