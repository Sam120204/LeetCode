class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = [float("inf") for i in range(len(prices))] # dp -> min price so far
        dp[0] = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            dp[i] = min(dp[i-1], prices[i])
            max_profit = max(max_profit, prices[i] - dp[i])
        return max_profit

        