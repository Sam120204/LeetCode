class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def dfs(x, y):
            # how to thinking about base cases
            # if current position is out of bounce
            if x < 0 or x >= m or y < 0 or y >= n:
                return 
            # think: meaning of the helper function.
            if grid[x][y] == "0":
                return
            
            # gurantees that grid[x][y] == "1"
            grid[x][y] = "0"
            dfs(x+1,y)
            dfs(x-1,y)
            dfs(x,y-1)
            dfs(x,y+1)
            

        count = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    dfs(i, j)
                    count += 1
        return count