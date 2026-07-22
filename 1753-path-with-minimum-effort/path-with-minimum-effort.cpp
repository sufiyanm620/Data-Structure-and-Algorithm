class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int effort=curr[0];
            int x=curr[1];
            int y=curr[2];
            if(x==m-1&&y==n-1) return effort;
            if(effort>dist[x][y]) continue;
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n){
                    int neweffort=max(effort,abs(heights[x][y]-heights[ni][nj]));
                    if(neweffort<dist[ni][nj]){
                        pq.push({neweffort,ni,nj});
                        dist[ni][nj]=neweffort;
                    }
                }
            }
        }
        return 0;
    }
};