class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>> directions{{0,-1},{-1,0},{0,1},{1,0}};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  pq.push({0,i,j});
                  dist[i][j]=0;
                  count++;
                }
            }
        }
        if(pq.empty()||count==m*n) return -1;
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=curr[0];
            int x=curr[1];
            int y=curr[2];
            pq.pop();
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==0){
                    if(dist[x][y]+1<dist[ni][nj]){
                        dist[ni][nj]=1+dist[x][y];
                        pq.push({dist[ni][nj],ni,nj});
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0&&dist[i][j]>ans)
                  ans=dist[i][j];
            }
        }
        return ans;
    }
};