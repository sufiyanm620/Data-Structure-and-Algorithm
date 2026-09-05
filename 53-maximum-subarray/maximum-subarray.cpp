class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ans=maxx;
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};