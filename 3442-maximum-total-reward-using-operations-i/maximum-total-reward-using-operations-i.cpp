class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,vector<int>& nums,int sum){
        if(i==n) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int pick=0;
        if(nums[i]>sum)
         pick = nums[i]+solve(i+1,nums,nums[i]+sum);
        int skip=solve(i+1,nums,sum);
        return dp[i][sum]=max(pick,skip);
    }
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        int maxx=nums.back();
        dp.assign(n,vector<int>(maxx*2+1,-1));
        return solve(0,nums,0);
    }
};