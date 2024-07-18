class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0; // If amount is 0, no coins are needed
        vector<int> dp(amount + 1, amount + 1); // Initialize dp array with amount+1 (infinity)
        dp[0] = 0; // Base case: 0 coins are needed to make amount 0
        
        // Iterate through each amount from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Check each coin
            for (const auto & coin : coins) {
                if (i >= coin) { // If the coin can be used
                    dp[i] = min(dp[i], dp[i - coin] + 1); // Update dp[i] with the minimum number of coins
                }
            }
        }
        
        // If dp[amount] is still amount+1, it means we couldn't find a combination of coins to make the amount
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
