class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
        dist[0][0]=0;
        int wt=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            wt=curr[0];
            int x=curr[1];
            int y=curr[2];
            if(x==m-1&&y==n-1) return wt;
            if(wt>dist[x][y]) continue;
            for(auto &d:dir){
                int ni=x+d[0];
                int nj=y+d[1];
                if(ni<m&&nj<n&&ni>=0&&nj>=0){
                    int nwt=max(abs(grid[x][y]-grid[ni][nj]),dist[x][y]);
                    if(nwt<dist[ni][nj]){
                        dist[ni][nj]=nwt;
                        pq.push({nwt,ni,nj});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};