class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            map<char, int> row_dict;
            map<char, int> col_dict;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.' and row_dict.find(board[row][col]) != row_dict.end()) {
                    return false;
                }
                row_dict[board[row][col]]++;
                if (board[col][row] != '.' and col_dict.find(board[col][row]) != col_dict.end()) {
                    return false;
                }
                col_dict[board[col][row]]++;
            }
        }
        
        for (int i =0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int row = i * 3, col = j * 3;
               
                map<char, int> grid_dict;
                for (int m = row; m < row+3; m++) {
                    for (int n = col; n < col+3; n++) {
                        if (board[m][n] != '.' and grid_dict.find(board[m][n]) != grid_dict.end()) {
                            return false;
                        }
                        grid_dict[board[m][n]]++;
                    }
                }
            }
        }
        return true;
    }
};

// [".",".",".",".","5",".",".","1","."],
// [".","4",".","3",".",".",".",".","."],
// [".",".",".",".",".","3",".",".","1"],
// ["8",".",".",".",".",".",".","2","."],
// [".",".","2",".","7",".",".",".","."],
// [".","1","5",".",".",".",".",".","."],
// [".",".",".",".",".","2",".",".","."],
// [".","2",".","9",".",".",".",".","."],
// [".",".","4",".",".",".",".",".","."]