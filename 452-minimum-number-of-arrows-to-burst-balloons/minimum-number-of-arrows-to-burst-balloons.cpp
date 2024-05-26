class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // [1,6],[2,8],[7,12],[10,16]
        if (points.size() == 1) return 1;
        sort(points.begin(), points.end(), [](vector<int>&s1, vector<int>& s2) {
            return s1[0]<s2[0];
        });
        
        int res = 1, cur = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            
            if (points[i][0] > cur) {
                
                res++;
                cur = points[i][1];
            } else {
                cur = min(cur, points[i][1]);
            }
        }
        return res;

    }
};