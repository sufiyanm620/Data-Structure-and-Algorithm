class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>> &grid){
        if(i==m-1&&j==n-1) return 1;
        if(i>=m||j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=0;
        if(i+1<m&&grid[i+1][j]!=1)
          right=solve(i+1,j,grid);
        int down=0;
        if(j+1<n&&grid[i][j+1]!=1)
            down=solve(i,j+1,grid);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(grid[0][0]==1||grid[m-1][n-1]==1) return 0;
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,grid);
    }
};