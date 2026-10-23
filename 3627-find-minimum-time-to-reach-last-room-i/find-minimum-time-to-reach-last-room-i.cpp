class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=curr[0];
            int i=curr[1];
            int j=curr[2];
            pq.pop();
            if(wt>dist[i][j]) continue;
            if(i==m-1&&j==n-1) return dist[i][j];
            for(auto &d:dir){
                int ni=i+d[0];
                int nj=j+d[1];
                if(ni<0||nj<0||ni>=m||nj>=n) continue;
                int newDist=max(grid[ni][nj],dist[i][j])+1;
                if(dist[ni][nj]>newDist){
                          dist[ni][nj]=newDist;
                          pq.push({newDist,ni,nj});
                       
                }
            }
        }
        return dist[m-1][n-1];
    }
};