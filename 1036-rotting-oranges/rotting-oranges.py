class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.append([i,j])
        count = 0

        # doing bfs for each layer
        dir = [[-1,0], [1,0], [0,1], [0,-1]]
        while q:
            size = len(q)
            print(q)
            for i in range(size):
                cur = q.popleft()
                for j in range(4):
                    new_row, new_col = cur[0] + dir[j][0], cur[1] + dir[j][1]
                    if new_row < 0 or new_row >= len(grid) or new_col < 0 or new_col >= len(grid[0]):
                        continue
                    if grid[new_row][new_col] == 1:
                        q.append([new_row, new_col])
                        grid[new_row][new_col] = 2
            count += 1

        # check if all has been rotten
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1

        return count - 1 if count > 0 else 0