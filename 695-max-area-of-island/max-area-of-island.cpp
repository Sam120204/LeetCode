class Solution {
    int dfs(vector<vector<int>>& grid, int row, int col, int& res) {
        if (grid[row][col] == 0) return 0;
        grid[row][col] = 2;
        vector<vector<int>> dir{{-1,0}, {0,1}, {0,-1}, {1,0}};
        int temp = 1;
        for (auto & d:dir) {
            int x_inc = d[0], y_inc = d[1];
            int new_r = row+x_inc, new_c = col+y_inc;
            if (new_r >= 0 and new_r <= grid.size()-1 and new_c >= 0 and new_c <= grid[0].size()-1 and grid[new_r][new_c] == 1) {
                temp += dfs(grid, new_r, new_c, res);
            }

        }
        res = max(res, temp);
        return temp;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, res);
                }
            }
        }

        return res;
    }
};