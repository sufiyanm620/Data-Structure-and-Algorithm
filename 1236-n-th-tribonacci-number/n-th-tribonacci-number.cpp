class Solution {
public:
    int solve(int n,int i,int a,int b,int c ,vector<int>& dp){
        if(i==n) return a+b+c;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=solve(n,i+1,b,c,a+b+c,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
         int a=0;
         int b=1;
         int c=1;
         if(n==0) return 0;
         if(n==1||n==2) return 1;
      
         return solve(n,3,a,b,c,dp);
         
    }
};