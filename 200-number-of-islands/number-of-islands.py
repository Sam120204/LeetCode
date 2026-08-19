class Solution:
    def dfs(self, grid: List[List[str]], row: int, col: int) -> None:
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]) or grid[row][col] != "1":
            return

        grid[row][col] = "0"
        dir = [[-1,0],[0,1],[1,0],[0,-1]]
        for i in dir:
            self.dfs(grid, row + i[0], col + i[1])
       
        return 

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    count+=1
                    self.dfs(grid, i, j)
        return count
        