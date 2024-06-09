class Solution {
    bool if_valid(int r, int c, int n, vector<vector<string>>& board) {
        // Check column and both diagonals
        for (int i = 0; i < r; i++) {
            // Check column
            if (board[i][c] == "Q") return false;
            // Check top-left to bottom-right diagonal
            if (c - (r - i) >= 0 && board[i][c - (r - i)] == "Q") return false;
            // Check top-right to bottom-left diagonal
            if (c + (r - i) < n && board[i][c + (r - i)] == "Q") return false;
        }
        return true;
    }

    void backtrack(int row, int n, vector<vector<string>>& board, vector<vector<string>>& solutions) {
        if (row == n) {
            vector<string> solution;
            for (auto& row : board) {
                string rowStr = "";
                for (auto& cell : row) {
                    rowStr += cell;
                }
                solution.push_back(rowStr);
            }
            solutions.push_back(solution);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (board[row][col] == ".") {
                board[row][col] = "Q";
                if (if_valid(row, col, n, board)) {
                    backtrack(row + 1, n, board, solutions);
                }
                board[row][col] = ".";
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> solutions;
        backtrack(0, n, board, solutions);
        return solutions;
    }
};
