class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                if(grid[i][j]==1){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    vis[i][j]=1;
                    while(!que.empty()){
                        auto [x,y]=que.front();
                        que.pop();
                        count++;
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==1&&!vis[ni][nj]){
                                que.push({ni,nj});
                                vis[ni][nj]=1;
                            }
                        }
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};