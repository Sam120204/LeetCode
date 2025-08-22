class Solution(object):
    def maxArea(self, height):
        i, j = 0, len(height) - 1
        best = 0
        while i < j:
            h = min(height[i], height[j])
            best = max(best, h * (j - i))
            # Greedy rule: move the shorter wall inward
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return best
