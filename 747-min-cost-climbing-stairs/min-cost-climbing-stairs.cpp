class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0] = cost[0], dp[1] = cost[1];
        if (cost.size() == 2) return min(cost[0], cost[1]);
        for (int i = 2; i < dp.size(); i++) {
            if (i != dp.size() - 1) {
                dp[i] = min(dp[i-2] + cost[i], dp[i-1] + cost[i]);
            } else {
                dp[i] = min(dp[i-1], dp[i-2]);
            }
        }
        return dp[cost.size()];
    }
};