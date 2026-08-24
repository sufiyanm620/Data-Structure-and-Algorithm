class Solution {
public:
    int n;
    int solve(int i,vector<int> &nums,int prev,vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1||nums[i]%nums[prev]==0){
            take=1+solve(i+1,nums,i,dp);
        }
        int skip=solve(i+1,nums,prev,dp);
        return dp[i][prev+1]=max(take,skip);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1)); 
         vector<int> ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,-1,dp);
        int i=0;
        int prev=-1;
        while(i<n){
            int take=-1;
            if(prev==-1||nums[i]%nums[prev]==0){
                take=1+solve(i+1,nums,i,dp);
            }
            int best=solve(i,nums,prev,dp);
            if(take==best){
                ans.push_back(nums[i]);
                prev=i;
            }
            i++;
        }
        return ans;
          

    }
};