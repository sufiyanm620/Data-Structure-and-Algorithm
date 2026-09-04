class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> mat(m,vector<int>(n,INT_MAX));
        mat[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
                auto curr=pq.top();
                pq.pop();
                int wt=curr[0];
                int x=curr[1];
                int y=curr[2];
                if(x==m-1&&y==n-1) return wt;
                if(wt>mat[x][y]) continue;
                for(auto &d:dir){
                    int nr=x+d[0];
                    int nc=y+d[1];
                    if(nr<0||nc<0||nr>=m||nc>=n) continue;
                    int nwt=max(wt,grid[nr][nc]);
                    if(nwt<mat[nr][nc]){
                        mat[nr][nc]=nwt;
                        pq.push({nwt,nr,nc});
                    }
                }
            }
        return mat[m-1][n-1];
    }
};