class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        int ans = 0;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[i-1],nums[i]);
            ans=max(ans,nums[i]-dp[i]);
        }
        return ans;
        
    }
};