#include <vector>
#include <set>

using namespace std;

class Solution {
    void dfs(vector<vector<int>>& heights, set<pair<int, int>>& ocean, int r, int c) {
        static const vector<int> dir = {-1, 0, 1, 0, -1};
        ocean.insert({r, c});
        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i], new_c = c + dir[i+1];
            if (new_r >= 0 && new_r < heights.size() && 
                new_c >= 0 && new_c < heights[0].size() && 
                heights[new_r][new_c] >= heights[r][c] && 
                ocean.find({new_r, new_c}) == ocean.end()) {
                dfs(heights, ocean, new_r, new_c);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> pacific, atlantic;
        int rows = heights.size();
        int cols = heights[0].size();

        for (int i = 0; i < cols; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, rows - 1, i);
        }
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, cols - 1);
        }

        vector<vector<int>> res;
        for (const auto& p : pacific) {
            if (atlantic.find(p) != atlantic.end()) {
                res.push_back({p.first, p.second});
            }
        }

        return res;
    }
};
