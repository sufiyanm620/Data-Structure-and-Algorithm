class Solution {
public:
    int n;
    int solve(vector<int>& coins, int amount,int i,vector<vector<int>> &dp){
       if(amount==0) return 0;
        if(i>=n) return 1e9; 
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=1e9;
        if(coins[i]<=amount){
             take=1+solve(coins,amount-coins[i],i,dp);
        }
        int skip=solve(coins,amount,i+1,dp);
        return dp[i][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  solve(coins,amount,0,dp);
        return (ans>=1e9)?-1:ans;
    }
};