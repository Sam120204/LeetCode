class Solution {
public:

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 or row >= board.size() or col < 0 or col >= board[0].size() or board[row][col] != 'O') {
            return;
        }
        board[row][col] = 'B';
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);

    }
    void solve(vector<vector<char>>& board) {
        if (board.empty() or board[0].empty()) return;
        // do dfs from the boarder
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[m-1][i] == 'O') dfs(board, m-1, i);
        }

        // do the flip
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
};