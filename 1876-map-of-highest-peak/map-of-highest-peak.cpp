class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> mat(m,vector<int>(n,-1));
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
        queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                mat[i][j]=0;
                que.push({i,j});
            }
         }
        }
        while(!que.empty()){
            auto [x,y]=que.front();
            que.pop();
            for(auto &d:dir){
                int ni=x+d[0];
                int nj=y+d[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&mat[ni][nj]==-1){
                    mat[ni][nj]=1+mat[x][y];
                    que.push({ni,nj});
                }

            }
        }
        
        return mat;
    }
};