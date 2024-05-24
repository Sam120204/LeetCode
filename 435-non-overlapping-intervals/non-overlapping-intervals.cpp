class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int removed = 0, target = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < target) {
                ++removed;
            } else {
                target = intervals[i][1];
            }
        }
        return removed-1;
    }
};