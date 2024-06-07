class Solution {
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
        static const vector<int> dir = {-1, 0, 1, 0, -1};
        ocean[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i], new_c = c + dir[i + 1];
            if (new_r < 0 || new_r >= heights.size() || 
                new_c < 0 || new_c >= heights[0].size() || 
                ocean[new_r][new_c] || heights[r][c] > heights[new_r][new_c])
                continue;
            dfs(heights, ocean, new_r, new_c);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        // Initialize edges for Pacific Ocean
        for (int i = 0; i < cols; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, rows - 1, i);
        }
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, cols - 1);
        }

        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
