class Solution {
public:
    int total=0;
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int r,int c,vector<vector<int>>& grid,int m,int n,int &total){
        total+=grid[r][c];
        grid[r][c]=0;
        for(auto &d:dir){
        int ni=r+d[0];
        int nj=c+d[1];
        if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]!=0){
            dfs(ni,nj,grid,m,n,total);
        }
        } 
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int total=0;
                if(grid[i][j]!=0){
                dfs(i,j,grid,m,n,total);
                }
                ans=max(ans,total);
            }
        }
        return ans;
    }
};
// int total=0;
//                 queue<pair<int,int>> que;
//                 if(grid[i][j]!=0){
//                     total+=grid[i][j];
//                     que.push({i,j});
//                     grid[i][j]=0;
//                     while(!que.empty()){
//                       auto [x,y]=que.front();
//                        que.pop();
//                       for(auto &d:dir){
//                         int ni=x+d[0];
//                         int nj=y+d[1];
//                         if(ni<m&&nj<n&&ni>=0&&nj>=0&&grid[ni][nj]!=0){
//                             total+=grid[ni][nj];
//                             que.push({ni,nj});
//                             grid[ni][nj]=0;
//                         }
//                       }
//                     }
//                 }