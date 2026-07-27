class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({0,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=curr[0];
            int x=curr[1];
            int y=curr[2];
            pq.pop();
            if(x==m-1&&y==n-1) return wt;
            if(wt>dist[x][y]) continue;
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n){
                    int nwt=max(dist[x][y],abs(heights[x][y]-heights[ni][nj]));
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