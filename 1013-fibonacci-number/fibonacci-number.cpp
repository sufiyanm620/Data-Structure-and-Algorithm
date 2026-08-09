class Solution {
public:
     int solve(int i,vector<int> &dp){
        if(i==0||i==1) return i;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=solve(i-1,dp)+solve(i-2,dp);
     }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};