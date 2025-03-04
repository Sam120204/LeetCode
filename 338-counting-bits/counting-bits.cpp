class Solution {
public:
    vector<int> countBits(int n) {
        // 6 - 110
        // 7 - 111
        // 8 - 1000
        // 0 1 1 2 1 2 2 3 1 2 2 2 3 3 4 
        if (n == 0) return {0};
        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;


    }
};