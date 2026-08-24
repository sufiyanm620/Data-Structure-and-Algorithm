class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<tuple<int,int,int>> que;
        int steps=0;
        que.push({0,0,k});
        vis[0][0]=k;
        while(!que.empty()){
            int sz=que.size();
            while(sz--){
                auto [x,y,rem]=que.front();
                que.pop();
                if(x==m-1&&y==n-1) return steps;
                for(auto &d:dir){
                    int ni=x+d[0];
                    int nj=y+d[1];
                    if(ni<0||nj<0||ni>=m||nj>=n) continue;
                    int nrem=rem;
                    if(grid[ni][nj]==1) nrem--;
                    if(nrem<0) continue;
                    if(vis[ni][nj]>=nrem) continue;
                    vis[ni][nj]=nrem; 
                    que.push({ni,nj,nrem});
                }
            }
            steps++;
        }
        return -1;
    }
};