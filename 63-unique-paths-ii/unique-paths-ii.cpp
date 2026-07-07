class Solution {
public:
    int m;
    int n;
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        if(i>=m||j>=n) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = 0;
        if(i+1<m&&grid[i+1][j]!=1) 
            right = solve(grid,i+1,j,dp);
        int down = 0;
        if(j+1<n&&grid[i][j+1]!=1)
            down = solve(grid,i,j+1,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(grid[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid,0,0,dp);
    }
};