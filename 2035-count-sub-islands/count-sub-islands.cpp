class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int count=0;
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}}; 
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid2[i][j]==1&&!vis[i][j]){
                  bool flag=true;
                   queue<pair<int,int>> que;
                    que.push({i,j});
                    vis[i][j]=1;
                    if(grid1[i][j]==0) flag=false;
                     while(!que.empty()){
                    auto [x,y]=que.front();
                     que.pop();
                     for(auto &d:dir){
                        int ni=x+d[0];
                        int nj=y+d[1];
                        if(ni<0||nj<0||ni>=m||nj>=n) continue;
                        if(grid2[ni][nj]==1&&!vis[ni][nj]){
                            que.push({ni,nj});
                            vis[ni][nj]=1;
                            if(grid1[ni][nj]==0)
                                flag=false;
                        }
                    }     
                }
                if(flag) count++;
            }
                
            }
        }
        return count;
    }
};