#include "type/type.h"

class Solution1 {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        vector<int> degree(n, 0);

        for (auto&& e : edges) {
            int i = e[0] - 1;
            int j = e[1] - 1;
            g[i][j] = 1;
            g[j][i] = 1;
            degree[i]++;
            degree[j]++;
        }

        int min_deg = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!g[i][j])
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (!g[j][k] || !g[k][i])
                        continue;
                    int deg = degree[i] + degree[j] + degree[k] - 6;
                    if (min_deg == -1 || deg < min_deg) {
                        min_deg = deg;
                    }
                }
            }
        }

        return min_deg;
    }
};
