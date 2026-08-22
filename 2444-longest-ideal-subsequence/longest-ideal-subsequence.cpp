class Solution {
public:
    int n;
    int solve(string &s,int i,int prev,int k,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int pick=0;
        if(prev==-1||abs((s[i]-'a')-prev)<=k)
          pick=1+solve(s,i+1,s[i]-'a',k,dp);
        int skip=solve(s,i+1,prev,k,dp);
        return dp[i][prev+1]=max(pick,skip);
    }
    int longestIdealString(string s, int k) {
        n=s.size();
        vector<vector<int>> dp(n,vector<int>(27,-1));
        return solve(s,0,-1,k,dp);
    }
};