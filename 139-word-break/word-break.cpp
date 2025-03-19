class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 0; i <= n; i++) {
            for (const auto & w : wordDict) {
                int m = w.size();
                if (i >= m and s.substr(i-m, m) == w) {
                    dp[i] = dp[i-m];
                }
                if (dp[i]) break;
            }
        }
        return dp[n];
    }
};