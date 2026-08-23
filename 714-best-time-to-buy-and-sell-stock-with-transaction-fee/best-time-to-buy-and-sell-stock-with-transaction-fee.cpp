class Solution {
public:
    int n;
    int solve(int i,vector<int>& prices, int fee,bool canBuy,vector<vector<int>> &dp){
           if(i>=n) return 0;
           if(dp[i][canBuy]!=-1) return dp[i][canBuy];
           if(canBuy){
            int buy=-prices[i]+solve(i+1,prices,fee,false,dp);
            int skip=solve(i+1,prices,fee,true,dp);
            return dp[i][canBuy]=max(buy,skip);
           }
           else{
           int sell=-fee+prices[i]+solve(i+1,prices,fee,true,dp);
           int skip=solve(i+1,prices,fee,false,dp);
           return dp[i][canBuy]=max(sell,skip);
           }
    }
    int maxProfit(vector<int>& prices, int fee) {
         n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,fee,1,dp);
    }
};