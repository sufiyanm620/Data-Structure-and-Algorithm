class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
        pq.push({0,0,0});
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
            dist[0][0]=0;
        grid[0][0]==0?dist[0][0]=0:dist[0][0]=1;
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                auto curr=pq.top();
                int cost=curr[0];
                int i=curr[1];
                int j=curr[2];
                pq.pop();
                if(i==m-1&&j==n-1) return cost;
                for(auto &d:dir){
                    int ni=i+d[0];
                    int nj=j+d[1];
                    if(ni>=m||nj>=n||ni<0||nj<0) continue;
                    if(cost+grid[ni][nj]<dist[ni][nj]){
                        dist[ni][nj]=cost+grid[ni][nj];
                        pq.push({dist[ni][nj],ni,nj});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};