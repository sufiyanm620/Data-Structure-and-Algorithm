class Solution {
public:
     int m;
     int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i>=m||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+solve(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=max(solve(s,t,i+1,j,dp),solve(s,t,i,j+1,dp));
     }
    int longestPalindromeSubseq(string s) {
        m=s.size();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(s,t,0,0,dp);
        
    }
};