class Solution {
public:
    int n;
    int solve(vector<int>& nums,int prev,int i,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1||nums[i]>nums[prev]){
               take=1+solve(nums,i,i+1,dp);
        }
        int skip=solve(nums,prev,i+1,dp);
        return dp[i][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
     n=nums.size();
     vector<vector<int>> dp(n,vector<int>(n,-1));
     return solve(nums,-1,0,dp);    
    }
};