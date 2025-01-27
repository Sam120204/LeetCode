class Solution {
    void bfs_mark_island(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& second_island) {
        queue<pair<int, int>> temp;
        grid[r][c] = 2;
        int r_bound = grid.size(), c_bound = grid[0].size();
        temp.push(make_pair(r, c));
        second_island.push(make_pair(r, c));
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0, -1}}; 
        while (!temp.empty()) {
            int n = temp.size();
            auto [r, c] = temp.front();
            temp.pop();

            for (auto d : directions) {
                int x_inc = d[0];
                int y_inc = d[1];

                int new_r = r + x_inc, new_c = c + y_inc;
                if (new_r >= 0 and new_r < r_bound and new_c >= 0 and new_c < c_bound and grid[new_r][new_c] == 1) {
                    temp.push(make_pair(new_r, new_c));
                    second_island.push(make_pair(new_r, new_c));
                    grid[new_r][new_c] = 2;
                }
            }

        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int count = 0;
        int r, c;
        queue<pair<int, int>> second_island;
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        bool found = false;
        for (int i = 0; i < grid.size(); i++) {
            if (found) break;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    r = i, c = j;
                    bfs_mark_island(grid, r, c, second_island);
                    found = true;
                    break;
                }
            }
        }
        
        // doing bfs continued...
        int r_bound = grid.size(), c_bound = grid[0].size();
        while (!second_island.empty()) {
            int n = second_island.size();
            
            for (int i = 0; i < n; i++) {
                auto [r, c] = second_island.front();
                second_island.pop();
                for (auto d : directions) {
                    int x_inc = d[0];
                    int y_inc = d[1];

                    int new_r = r + x_inc, new_c = c + y_inc;
                    if (new_r >= 0 and new_r < r_bound and new_c >= 0 and new_c < c_bound) {
                        if (grid[new_r][new_c] == 1) return count;
                        if (grid[new_r][new_c] == 0) {
                            grid[new_r][new_c] = 2;
                            second_island.push(make_pair(new_r, new_c));
                        }
                    }
                }
            }
            count++;
        }


        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[0].size(); j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return count;
    }
};