class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int i = 1;
        int cur = points[0][1];
        int count = 1;
        while (i < points.size()) {
            if (points[i][0] <= cur) {
                i++;
            } else {
                count++;
                cur = points[i][1];
                i++;
            }
            
        }
        return count;
    }
};