class Solution {
public:
    int n;
    long long solve(vector<vector<int>>& nums,int i,vector<long long> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long pick=nums[i][0]+solve(nums,i+1+nums[i][1],dp);
        long long skip=solve(nums,i+1,dp);
        return dp[i]=max(pick,skip);
    }
    long long mostPoints(vector<vector<int>>& nums) {
        n=nums.size();
        vector<long long> dp(n+1,-1);
        return solve(nums,0,dp);
    }
};