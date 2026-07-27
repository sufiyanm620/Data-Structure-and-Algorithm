class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}; 
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
       int m=grid.size();
       int n=grid[0].size();
       if(grid[0][0]==1||grid[m-1][n-1]) return -1;
       vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
       dist[0][0]=1;
       pq.push({1,0,0});
       while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int d=curr[0];
        int x=curr[1];
        int y=curr[2];
        if(d>dist[x][y]) continue;
        if(x==m-1&&y==n-1) return d;
        for(auto &dir:directions){
            int ni=x+dir[0];
            int nj=y+dir[1];
            if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==0){
                    if(d+1<dist[ni][nj]){
                        dist[ni][nj]=d+1;
                        pq.push({dist[ni][nj],ni,nj});
                    }
            }
           }
        }
        return -1;

    }
};