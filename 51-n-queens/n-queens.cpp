class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        
        backtrack(0, n, board, cols, diag1, diag2, res);
        return res;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<int>& cols,
                   vector<int>& diag1, vector<int>& diag2, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;
            
            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            // Move to the next row
            backtrack(row + 1, n, board, cols, diag1, diag2, res);

            // Backtrack: Remove the queen
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
};