class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((grid[i][j]==0)&&(i==0||j==0||i==m-1||j==n-1)){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    grid[i][j]=1;
                    vis[i][j]=true;
                    while(!que.empty()){
                        int sz=que.size();
                        while(sz--){
                        auto curr=que.front();
                        que.pop();
                        int x=curr.first;
                        int y=curr.second;
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&!grid[ni][nj]&&!vis[ni][nj]){
                                que.push({ni,nj});
                                vis[ni][nj]=true;
                                grid[ni][nj]=1;
                            }
                        }
                    }
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    vis[i][j]=true;
                    count++;
                    while(!que.empty()){
                      int sz=que.size();
                      while(sz--){
                        auto curr=que.front();
                        que.pop();
                        int x=curr.first;
                        int y=curr.second;
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni<m&&nj<n&&ni>=0&&nj>=0&&!grid[ni][nj]&&!vis[ni][nj]){
                                vis[ni][nj]=true;
                                que.push({ni,nj});
                                grid[ni][nj]=1;
                            }
                        }
                      }
                    }
                }
            }

        }
        return count;
    }
};