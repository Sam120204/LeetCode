// class Solution {
//     int bfs(vector<vector<int>>& mat, int i, int j) {
//         int m = mat.size(), n = mat[0].size();
//         if (i < 0 or i >= m or j < 0 or j >= n) return -1;

//         queue<pair<int, int>> q;
//         vector<vector<bool>> visited(m, vector<bool>(n, false)); // Track visited cells
//         q.push({i, j});
//         visited[i][j] = true;  // Mark start cell as visited

//         vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//         int count = 0;

//         while (!q.empty()) {
//             int s = q.size();
//             for (int k = 0; k < s; k++) {  // Change loop variable to `k` to avoid shadowing `j`
//                 pair<int, int> cur = q.front();
//                 q.pop();

//                 for (int d = 0; d < 4; d++) {  // Change loop variable to `d` to avoid shadowing `i`
//                     int new_i = cur.first + dir[d][0], new_j = cur.second + dir[d][1];

//                     // Check bounds first before accessing matrix
//                     if (new_i >= 0 and new_i < m and new_j >= 0 and new_j < n and !visited[new_i][new_j]) {
//                         if (mat[new_i][new_j] == 0) return count + 1;  // Fix: return count + 1
//                         q.push({new_i, new_j});
//                         visited[new_i][new_j] = true;  // Mark visited
//                     }
//                 }
//             }
//             count++;
//         }
//         return count;
//     }

// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] != 0) dp[i][j] = bfs(mat, i, j);
//             }
//         }

//         return dp;
//     }
// };
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1)); // -1 means unprocessed
        queue<pair<int, int>> q;

        // Step 1: Initialize queue with all '0' cells and set their distance to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0; // Distance for '0' cells is 0
                }
            }
        }

        // Step 2: Multi-source BFS to update distances
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [cur_i, cur_j] = q.front();
            q.pop();

            for (auto& d : dir) {
                int new_i = cur_i + d[0], new_j = cur_j + d[1];

                // Skip out-of-bounds or already visited cells
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || dist[new_i][new_j] != -1) 
                    continue;

                dist[new_i][new_j] = dist[cur_i][cur_j] + 1;
                q.push({new_i, new_j});
            }
        }

        return dist;
    }
};
