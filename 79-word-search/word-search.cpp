class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, string& word, int target_index, bool& find) {
        if (find) return; // Stop recursion if word is already found
        
        if (target_index == word.size()) { // If word is found
            find = true;
            return;
        }

        // Boundary conditions + character mismatch check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[target_index]) {
            return;
        }

        char temp = board[i][j]; // Store original character
        board[i][j] = '#'; // Mark cell as visited

        // Prioritize searching in directions that are most likely to succeed
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // Down, Right, Up, Left (prioritizing forward movement)
        
        for (auto &d : dir) {
            dfs(board, i + d[0], j + d[1], word, target_index + 1, find);
            if (find) return; // Stop unnecessary recursion
        }

        board[i][j] = temp; // Restore cell (Backtracking)
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool find = false;

        // Early pruning: Check if board contains enough characters
        unordered_map<char, int> board_freq, word_freq;
        for (auto &row : board) {
            for (char c : row) board_freq[c]++;
        }
        for (char c : word) word_freq[c]++;
        for (auto [c, count] : word_freq) {
            if (board_freq[c] < count) return false; // If board has fewer chars than needed, return early
        }

        // Start DFS from every matching first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, i, j, word, 0, find);
                    if (find) return true;
                }
            }
        }
        return false;
    }
};
