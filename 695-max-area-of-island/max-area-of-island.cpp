class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {
        // base case:
        if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0) return 0;
        // here means it is in the bound and the current pos is 1
        grid[r][c] = 0;
        return 1 + dfs(grid, r-1,c) + dfs(grid, r+1,c)+ dfs(grid, r,c+1)+ dfs(grid, r,c-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxx = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                maxx = max(maxx, dfs(grid, i, j));
            }
        }
        return maxx;
    }
};