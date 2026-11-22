class Solution {
public:
    int n;
    int solve(vector<int>& dp,int i,int n,vector<int>& nums){
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int j=1;j<=nums[i]&&i+j<n;j++){
               int temp =solve(dp,i+j,n,nums);
               if(temp!=INT_MAX)
               ans=min(ans,1+temp);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        vector<int> dp(n+1,-1);
         return solve(dp,0,n,nums);
    }
};