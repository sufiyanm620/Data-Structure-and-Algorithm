class Solution {
public:
    int m;
    int n;
    bool solve(string &s1, string &s2, string &s3,int i,int j,vector<vector<int>> &dp){
        if(i==m&&j==n) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int k = i+j;
        bool ans=false;
        if(i<m&&s1[i]==s3[k])
            ans|=solve(s1,s2,s3,i+1,j,dp);
         if(j<n&&s2[j]==s3[k])
            ans|=solve(s1,s2,s3,i,j+1,dp);
    
          return dp[i][j]=ans;    
    }
    bool isInterleave(string s1, string s2, string s3) {
         m = s1.size();
         n = s2.size();
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
         if(m+n!=s3.size()) return false;
         return solve(s1,s2,s3,0,0,dp);

    } 
};