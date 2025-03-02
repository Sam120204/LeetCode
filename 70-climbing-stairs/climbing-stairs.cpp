class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        //dp[i] means in the current top, the max way to climb
        // n = 4
        // [0,1,2,3,5]
        if (n == 1) return 1;
        if (n==2) return 2;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        for (auto i : dp) cout << i << " ";
        return dp[n];
    }
};