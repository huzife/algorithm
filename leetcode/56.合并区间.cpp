#include "type/type.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        int left = intervals[0][0];
        int right = intervals[0][1];
        for (auto& i : intervals) {
            if (i[0] > right) {
                ans.push_back({left, right});
                left = i[0];
                right = i[1];
            } else {
                left = min(i[0], left);
                right = max(i[1], right);
            }
        }

        ans.push_back({left, right});

        return ans;
    }
};
