class Solution {
public:
     int m;
     int n;
     vector<vector<vector<int>>> dp;
     int solve(int i,int j,vector<vector<int>>& grid,int cost){
        if(i>=m||j>=n||cost<0) return -1000000000;
        if(i==m-1&&j==n-1) return 0;
        if(dp[i][j][cost]!=-1) return dp[i][j][cost];
        int down=-1000000000;
        if(i+1<m){
            if(grid[i+1][j]==2){
                down=2+solve(i+1,j,grid,cost-1);
            }
            else if(grid[i+1][j]==1){
                down=1+solve(i+1,j,grid,cost-1);
            }
            else{
                down=solve(i+1,j,grid,cost);
            }
        }
        int right=-1000000000;
        if(j+1<n){
            if(grid[i][j+1]==2){
                right=2+solve(i,j+1,grid,cost-1);
            }
            else if(grid[i][j+1]==1){
                right=1+solve(i,j+1,grid,cost-1);
            }
            else{
                right=solve(i,j+1,grid,cost);
            }
        }
        return dp[i][j][cost]=max(right,down);
        
     }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int st=grid[0][0]==0?0:1;
        if(st>k) return -1;
        int ans=grid[0][0]+solve(0,0,grid,k-st);
        return ans<0?-1:ans;
    }
};