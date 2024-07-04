class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); i++) {
            for (const auto & word : wordDict) {
                if (i>=word.size() and s.substr(i-word.size(), word.size()) == word) {

                    dp[i] = dp[i] or dp[i-word.size()];
                }
            }
        }
        // for (auto b : dp) cout << b << " ";
        return dp[s.size()];
    }
};