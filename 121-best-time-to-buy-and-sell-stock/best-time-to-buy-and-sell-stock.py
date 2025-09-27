class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = [float("inf") for i in range(len(prices))] # dp[i] we want is min price we have looked so far
        dp[0] = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            dp[i] = min(prices[i], dp[i-1])
            max_profit = max(max_profit, prices[i] - dp[i])
        return max_profit
