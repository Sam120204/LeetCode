class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    int n = grid.size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;
    q.push({x, y});

    while (!s.empty()) {
        auto [cx, cy] = s.top();
        s.pop();
        for (auto [dx, dy] : directions) {
            int nx = cx + dx;
            int ny = cy + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                s.push({nx, ny});
                q.push({nx, ny});
            }
        }
    }
}

void findFirstIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j, visited, q);
                return;
            }
        }
    }
}

int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // Step 1: Find the first island and mark all its 1s
    findFirstIsland(grid, visited, q);

    // Step 2: BFS to find the shortest bridge
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (grid[nx][ny] == 1) {
                        return steps;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        ++steps;
    }

    return -1;  // Should never reach here if the input is guaranteed to have exactly two islands
}
};