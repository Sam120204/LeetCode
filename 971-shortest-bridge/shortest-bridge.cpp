class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,queue<pair<int,int>>& q){
        if(i<0 || i>=grid.size() || j>=grid.size() || j<0 || grid[i][j]==-1 || grid[i][j]==0) return;
        grid[i][j]=-1;
        q.push({i,j});
        dfs(i,j-1,grid,q);
        dfs(i,j+1,grid,q);
        dfs(i-1,j,grid,q);
        dfs(i+1,j,grid,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        int b=true;
        for(int i=0;i<n;i++){
        if(b){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,q);
                    b=false;
                    break;
                }
            }
        }
        }
        int ans=0;
        int r[]={-1,1,0,0};
        int c[]={0,0,-1,1};
        while(!q.empty()){
            int a=q.size();
            while(a--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=i+r[k];
                    int nc=j+c[k];
                    if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc]==-1) continue;
                    if(grid[nr][nc]==1) return ans;
                    grid[nr][nc]=-1;
                    q.push({nr,nc});
                }
            }
            ans++;
        }
        return ans;
    }
};