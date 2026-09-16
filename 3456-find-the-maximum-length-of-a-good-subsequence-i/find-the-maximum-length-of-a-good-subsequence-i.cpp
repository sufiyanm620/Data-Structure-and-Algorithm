class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int prev,int i,vector<int>& nums, int k){
        if(i==n) return 0;
        if(dp[i][prev+1][k]!=-1) return dp[i][prev+1][k];
        int skip=solve(prev,i+1,nums,k);
        int take=0;
        if(prev==-1)
         take=1+solve(i,i+1,nums,k);
        else if(nums[i]==nums[prev])
          take=1+solve(i,i+1,nums,k);
        else if(k>0)
         take=1+solve(i,i+1,nums,k-1);
        return dp[i][prev+1][k]=max(take,skip);
    }

    int maximumLength(vector<int>& nums, int k) {
        n=nums.size();
        dp.resize(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(-1,0,nums,k);    
    }
};