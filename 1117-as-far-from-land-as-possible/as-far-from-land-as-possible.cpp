class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> dist(m,vector<int>(n,-1));
        vector<vector<int>> directions{{0,-1},{-1,0},{0,1},{1,0}};
         queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  que.push({i,j});
                  dist[i][j]=0;
                  count++;
                }
            }
        }
        int ans=0;
        if(que.empty()||count==m*n) return -1;
        while(!que.empty()){
            auto [x,y]=que.front();
            que.pop();
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                for(auto &dir:directions){
                    if(ni>=0&&nj>=0&&ni<m&&nj<n&&dist[ni][nj]==-1){
                            dist[ni][nj]=1+dist[x][y];
                            que.push({ni,nj});
                            ans=max(ans,dist[ni][nj]);
                    }
                }
            }
        }
        return ans;
    }
};