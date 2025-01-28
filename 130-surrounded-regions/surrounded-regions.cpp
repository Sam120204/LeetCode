class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'F';
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                board[i][n-1] = 'F';
                q.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'F';
                q.push({0, j});
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = 'F';
                q.push({m - 1, j});
            }
        }

        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int queue_size = q.size();
            
            for (int i = 0; i < queue_size; i++) {
                auto [x,y] = q.front();
                q.pop();
                for (auto& d : dir) {
                    int x_inc = d[0];
                    int y_inc = d[1];
                    int new_x = x + x_inc;
                    int new_y = y + y_inc;
                    if (not (new_x < 0 or new_x >= m or new_y < 0 or new_y>=n) and board[new_x][new_y] == 'O') {
                        board[new_x][new_y] = 'F';
                        q.push({new_x,new_y});
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if (board[i][j] == 'F') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};