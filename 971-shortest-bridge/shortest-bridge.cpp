class Solution {
    // void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    //     int n = grid.size();
    //     vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    //     stack<pair<int, int>> s;
    //     s.push({x, y});
    //     visited[x][y] = true;
    //     q.push({x, y});

    //     while (!s.empty()) {
    //         auto [cx, cy] = s.top();
    //         s.pop();
    //         for (auto [dx, dy] : directions) {
    //             int nx = cx + dx;
    //             int ny = cy + dy;
    //             if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 1) {
    //                 visited[nx][ny] = true;
    //                 s.push({nx, ny});
    //                 q.push({nx, ny});
    //             }
    //         }
    //     }
    // }

    // void findFirstIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    //     int n = grid.size();
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             if (grid[i][j] == 1) {
    //                 dfs(grid, i, j, visited, q);
    //                 return;
    //             }
    //         }
    //     }
    // }

    // int shortestBridge(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     vector<vector<bool>> visited(n, vector<bool>(n, false));
    //     queue<pair<int, int>> q;

    //     // Step 1: Find the first island and mark all its 1s
    //     findFirstIsland(grid, visited, q);

    //     // Step 2: BFS to find the shortest bridge
    //     vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    //     int steps = 0;

    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; ++i) {
    //             auto [x, y] = q.front();
    //             q.pop();
    //             for (auto [dx, dy] : directions) {
    //                 int nx = x + dx;
    //                 int ny = y + dy;
    //                 if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
    //                     if (grid[nx][ny] == 1) {
    //                         return steps;
    //                     }
    //                     q.push({nx, ny});
    //                     visited[nx][ny] = true;
    //                 }
    //             }
    //         }
    //         ++steps;
    //     }

    //     return -1;  // Should never reach here if the input is guaranteed to have exactly two islands
    // }
public:
    // void dfs(int i,int j,vector<vector<int>>& grid,queue<pair<int,int>>& q){
    //     if(i<0 || i>=grid.size() || j>=grid.size() || j<0 || grid[i][j]==-1 || grid[i][j]==0) return;
    //     grid[i][j]=-1;
    //     q.push({i,j});
    //     dfs(i,j-1,grid,q);
    //     dfs(i,j+1,grid,q);
    //     dfs(i-1,j,grid,q);
    //     dfs(i+1,j,grid,q);
    // }
    // int shortestBridge(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     queue<pair<int,int>> q;
    //     int b=true;
    //     for(int i=0;i<n;i++){
    //     if(b){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==1){
    //                 dfs(i,j,grid,q);
    //                 b=false;
    //                 break;
    //             }
    //         }
    //     }
    //     }
    //     int ans=0;
    //     int r[]={-1,1,0,0};
    //     int c[]={0,0,-1,1};
    //     while(!q.empty()){
    //         int a=q.size();
    //         while(a--){
    //             int i=q.front().first;
    //             int j=q.front().second;
    //             q.pop();
    //             for(int k=0;k<4;k++){
    //                 int nr=i+r[k];
    //                 int nc=j+c[k];
    //                 if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc]==-1) continue;
    //                 if(grid[nr][nc]==1) return ans;
    //                 grid[nr][nc]=-1;
    //                 q.push({nr,nc});
    //             }
    //         }
    //         ans++;
    //     }
    //     return ans;
    // }
    void bfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    int n = grid.size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> islandQueue;
    islandQueue.push({x, y});
    visited[x][y] = true;
    q.push({x, y});

    while (!islandQueue.empty()) {
        auto [cx, cy] = islandQueue.front();
        islandQueue.pop();
        for (auto [dx, dy] : directions) {
            int nx = cx + dx;
            int ny = cy + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    islandQueue.push({nx, ny});
                    q.push({nx, ny});
                }
            }
        }
    }
}

void findFirstIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                bfs(grid, i, j, visited, q);
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