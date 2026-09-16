class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int i,vector<int> &prices,bool canBuy,int k){
        if(i==n||k==0) return 0;
        if(dp[i][canBuy][k]!=-1) return dp[i][canBuy][k];
        if(canBuy){
            int buy=-prices[i]+solve(i+1,prices,0,k);
            int skip=solve(i+1,prices,1,k);
            return dp[i][canBuy][k]=max(buy,skip);
        }
            int sell=prices[i]+solve(i+1,prices,1,k-1);
            int skip=solve(i+1,prices,0,k);
            return dp[i][canBuy][k]=max(sell,skip);
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,prices,1,k);
    }
};