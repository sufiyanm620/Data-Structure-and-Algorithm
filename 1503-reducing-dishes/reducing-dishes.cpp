class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int> &nums){
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick=nums[i]*j+solve(i+1,j+1,nums);
        int skip=solve(i+1,j,nums);
        return dp[i][j]=max(pick,skip);
    }
    int maxSatisfaction(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,1,nums);
    }
};