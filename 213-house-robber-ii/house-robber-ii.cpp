class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp,int ans,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+solve(nums,i+2,dp,ans,n),solve(nums,i+1,dp,ans,n));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        if(n<2) return nums[0];
        return max(solve(nums,1,dp1,0,n),solve(nums,0,dp2,0,n-1));
    }
};