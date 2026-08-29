class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> visi(m,vector<int>(n,0));
        bool flag=false;
         queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&!flag){
                queue<pair<int,int>> que;
                que.push({i,j});
                vis[i][j]=1;
                while(!que.empty()){
                    int sz=que.size();
                    while(sz--){
                        auto [x,y] =que.front();
                        que.pop();
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==1&&!vis[ni][nj]){
                                vis[ni][nj]=1;
                                que.push({ni,nj});
                            }
                        }
                    }
                }
                flag=true;
            }
        }
    }
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]&&!vis[i][j]){
                q.push({i,j});
                visi[i][j]=1;
            }
        }
    }
        int steps=0;
       
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(auto &d:dir){
                    int ni=x+d[0];
                    int nj=y+d[1];
                
                    if(ni>=0&&nj>=0&&ni<m&&nj<n&&!visi[ni][nj]){
                        if(vis[ni][nj]) return steps;
                        if(!visi[ni][nj]&&grid[ni][nj]==0){
                        q.push({ni,nj});
                        visi[ni][nj]=1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};