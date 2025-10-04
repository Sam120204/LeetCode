class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        N, M = len(word1), len(word2)

        dp = [[0 for j in range(M+1)] for i in range(N+1)]

        for i in range(N+1):
            dp[i][0] = i

        for j in range(M+1):
            dp[0][j] = j

        for i in range(1, N+1):
            for j in range(1, M+1):
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (1 if word1[i-1] != word2[j-1] else 0))

        return dp[-1][-1]