class Solution {
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited) {
        vector<vector<int>> dir{{-1,0}, {0,1}, {1,0}, {0, -1}};
        visited[r][c] = true;
        for (auto & d : dir) {
            int new_r = r + d[0], new_c = c + d[1];
            if (new_r >= 0 and new_r < heights.size() and new_c >= 0 and new_c < heights[0].size() and !visited[new_r][new_c] and heights[new_r][new_c] >= heights[r][c]) {
                dfs(heights, new_r, new_c, visited);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) dfs(heights, i, 0, pacific);
        for (int i = 0; i < n; i++) dfs(heights, 0, i, pacific);

        for (int i = 0; i < m; i++) dfs(heights, i, n-1, atlantic);
        for (int i = 0; i < n; i++) dfs(heights, m-1, i, atlantic);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] and atlantic[i][j]) {
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};