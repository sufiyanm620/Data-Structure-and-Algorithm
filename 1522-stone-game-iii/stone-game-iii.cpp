class Solution {
public:
    int n;
    int solve(int i,vector<int>& nums,vector<int> &dp){
             if(i>=n) return 0;
             if(dp[i]!=-1) return dp[i];
             int res=nums[i]-solve(i+1,nums,dp);
             
             if(i+1<n) res=max(res,nums[i]+nums[i+1]-solve(i+2,nums,dp));
             if(i+2<n) res=max(res,nums[i]+nums[i+1]+nums[i+2]-solve(i+3,nums,dp));
             return dp[i]=res;
    }
    string stoneGameIII(vector<int>& nums) {
         
         n=nums.size();
         vector<int> dp(n+1,-1);
         int sum=solve(0,nums,dp);
         if(sum<0) return "Bob";
         if(sum>0) return "Alice";
         return "Tie";
    }
};