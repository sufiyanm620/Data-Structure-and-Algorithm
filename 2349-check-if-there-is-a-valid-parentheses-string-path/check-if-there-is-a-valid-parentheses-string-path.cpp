class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>> dp;
    bool solve(int i,int j,int balance,vector<vector<char>>& grid){
        if(balance<0) return false;
        if(i==m-1&&j==n-1) return balance==0;
        if(dp[i][j][balance]!=-1) return dp[i][j][balance];
        bool ans=false;
        if(i+1<m){
            int nb=balance+(grid[i+1][j]=='('?1:-1);
            if(solve(i+1,j,nb,grid))
             ans=true;
        }
        if(j+1<n){
            int nb=balance+(grid[i][j+1]=='('?1:-1);
            if(solve(i,j+1,nb,grid))
             ans=true;
        }
        return dp[i][j][balance]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(m+n,-1)));
        if(grid[0][0]==')'||grid[m-1][n-1]=='(') return false;
         return solve(0,0,1,grid);
           
    }
};