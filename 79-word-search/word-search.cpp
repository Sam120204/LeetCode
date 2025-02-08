// class Solution {
//     void dfs(vector<vector<char>>& board, int i, int j, string& word, int target_index, bool& find) {
//         if (find) return; // Stop recursion early if word is found
        
//         if (target_index == word.size()) { // If the entire word is found
//             find = true;
//             return;
//         }

//         if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[target_index]) {
//             return; // Out of bounds or mismatch
//         }

//         char temp = board[i][j]; // Store original character
//         board[i][j] = '#'; // Mark as visited

//         vector<vector<int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
//         for (auto &d : dir) {
//             dfs(board, i + d[0], j + d[1], word, target_index + 1, find);
//             if (find) return; // Stop unnecessary recursion if word is found
//         }

//         board[i][j] = temp; // Restore character (Backtracking)
//     }

// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size(), n = board[0].size();
//         bool find = false;

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == word[0]) {
//                     dfs(board, i, j, word, 0, find);
//                     if (find) return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
class Solution {
    bool dfs(int x, int y, int m, int n, vector<vector<char>>& board, string& word, int c) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[c]) return false;
        if (c == word.size() - 1) return true;

        char temp = board[x][y];
        board[x][y] = '#'; 
        bool found = dfs(x + 1, y, m, n, board, word, c + 1) ||
                     dfs(x - 1, y, m, n, board, word, c + 1) ||
                     dfs(x, y + 1, m, n, board, word, c + 1) ||
                     dfs(x, y - 1, m, n, board, word, c + 1);
        board[x][y] = temp;
        return found;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, m, n, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};