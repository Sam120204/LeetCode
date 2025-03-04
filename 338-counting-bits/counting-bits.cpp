class Solution {
public:
    vector<int> countBits(int n) {
        // Key Observations
        // Every power of two has exactly one 1 in its binary representation.

        // 1 → 0001 → 1 one
        // 2 → 0010 → 1 one
        // 4 → 0100 → 1 one
        // 8 → 1000 → 1 one
        // Any number that is a power of two starts with a single 1 and the rest are 0s.
        // Numbers between two consecutive powers of two are formed by adding to previous numbers.

        // The numbers between 4 and 8 (5, 6, 7) are just 1 + (the number of ones in [5-4], [6-4], [7-4]).

        vector<int> dp(n + 1, 0);
        int powerOfTwo = 1;  // Track the most recent power of two
        
        for (int i = 1; i <= n; i++) {
            if (i == powerOfTwo * 2) { 
                powerOfTwo = i;  // Update power of two
            }
            dp[i] = dp[i - powerOfTwo] + 1;
        }
        
        return dp;


    }
};