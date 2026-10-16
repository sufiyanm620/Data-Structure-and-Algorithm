class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i,vector<int>& cost){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=min(cost[i]+solve(i+1,cost),cost[i]+solve(i+2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        dp.resize(n+1,-1);
        return min(solve(0,cost),solve(1,cost));
    }
};