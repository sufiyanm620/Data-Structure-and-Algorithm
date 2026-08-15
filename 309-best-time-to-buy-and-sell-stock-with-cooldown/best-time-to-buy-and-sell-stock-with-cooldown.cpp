class Solution {
public:
    int n;
    int solve(vector<int>& prices,int i,bool canBuy,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        if(canBuy){
            int buy=-prices[i]+solve(prices,i+1,0,dp);
            int skip=solve(prices,i+1,1,dp);
            return dp[i][canBuy]=max(buy,skip);
        }
         int  sell=prices[i]+solve(prices,i+2,1,dp);
         int skip=solve(prices,i+1,0,dp);
        return dp[i][canBuy]=max(skip,sell);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,true,dp);

    }
};