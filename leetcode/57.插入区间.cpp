#include "type/type.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int left, right;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        left = i;

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            i++;
        }
        right = i - 1;

        if (left > right) {
            ans.push_back(newInterval);
        }
        else {
            ans.push_back({min(intervals[left][0], newInterval[0]), max(intervals[right][1], newInterval[1])});
        }

        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};
