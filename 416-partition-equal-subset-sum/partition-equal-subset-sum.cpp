class Solution {
public:
    bool solve(vector<int>& nums,int i,int sum,vector<vector<int>> &dp){
        if(i>=nums.size()) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(sum==0) return true;
        bool take=false;
        if(nums[i]<=sum)
        take = solve(nums,i+1,sum-nums[i],dp);
        bool skip = false;
        skip = solve(nums,i+1,sum,dp);
       return dp[i][sum]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum+=x;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return solve(nums,0,sum/2,dp);

    }
};