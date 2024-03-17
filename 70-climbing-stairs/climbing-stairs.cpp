class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp = {};
        for (int i=0; i <= n; i++) {
            dp.emplace_back(0);
        }
        dp[0] = 1;
        dp[1] = 1;
        int len = n+1;
        for (int i = 2; i <= n; i++) {
            if (i < len) {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }

        return dp[len-1];
    }
};