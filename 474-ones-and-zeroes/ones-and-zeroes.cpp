class Solution {
    pair<int, int> count(const string & s) {
        int count0 = s.length(), count1 = 0;
        for (const char & c:s) {
            if (c == '1') {
                ++count1;
                --count0;
            }
        }
        return make_pair(count0, count1);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (const auto & i : strs) {
            auto [count0, count1] = count(i);
            for (int j = m; j >= count0; --j) {
                for (int p = n; p >= count1; --p) {
                    dp[j][p] = max(dp[j][p], 1+dp[j-count0][p-count1]);
                }
            }
        }
        return dp[m][n];
    }
};