class Solution {
public:
    int m;
    int n;
    int solve(string &s1, string &s2,int i,int j,vector<vector<int>> &dp){
        if(i>=m||j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
          return dp[i][j]=1+solve(s1,s2,i+1,j+1,dp);
        return dp[i][j]=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        m=s1.size();
        n=s2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(s1,s2,0,0,dp);
    }
};