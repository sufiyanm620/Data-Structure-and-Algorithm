class Solution {
public:
    int m;
    int n;
   int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i>=m||j>=n) return 0;
        if(i==m-1&&j==n-1) return grid[i][j];
        int left=INT_MAX;
        int down=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+1<m)
            left=solve(grid,i+1,j,dp);
        if(j+1<n)
            down=solve(grid,i,j+1,dp);
        return dp[i][j]=grid[i][j]+min(left,down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n+1,-1));
        return solve(grid,0,0,dp);
    }
};