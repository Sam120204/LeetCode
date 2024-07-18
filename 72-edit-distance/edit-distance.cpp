class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
                if (i == 0) {
                    dp[i][j] = j; // If word1 is empty, we need 'j' insertions to match word2[0...j-1]
                } else if (j == 0) {
                    dp[i][j] = i; // If word2 is empty, we need 'i' deletions to match word1[0...i-1]
                } else {
                    dp[i][j] = min(
                        min(dp[i-1][j], dp[i][j-1]) + 1, // Minimum of a deletion or insertion + 1
                        dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1) // If characters match, no substitution needed; otherwise, +1 for substitution
                    );
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
