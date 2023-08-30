#include "type/type.h"

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> record;
        int max_f = 0;
        for (auto i : forbidden) {
            record.insert(i);
            if (i > max_f) {
                max_f = i;
            }
        }
        record.insert(0);

        auto check = [&](int i) {
            return record.find(i) == record.end();
        };

        int jump = 0;
        int cur_cnt = 1;
        int next_cnt = 0;
        int bound;
        if (a == b) {
            bound = x;
        } else if (a > b) {
            bound = x + b;
        } else {
            bound = max(max_f + a + b, x);
        }

        queue<pair<int, bool>> pos;
        pos.push({0, true});

        while (!pos.empty()) {
            auto [i, back] = pos.front();
            pos.pop();

            if (i == x)
                return jump;

            if (back && i - b >= 0 && check(i - b)) {
                next_cnt++;
                pos.push({i - b, false});
                record.insert(i - b);
            }

            if (i + a <= bound && check(i + a)) {
                next_cnt++;
                pos.push({i + a, true});
                record.insert(i + a);
            }

            if (--cur_cnt == 0) {
                cur_cnt = next_cnt;
                next_cnt = 0;
                jump++;
            }
        }

        return -1;
    }
};
