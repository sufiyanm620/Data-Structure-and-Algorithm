class Solution {
public:
    long long mostPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<long long> dp(n+1,-1);
        for(int i=n-1;i>=0;i--){
            long long pick =nums[i][0];
            int j=i+nums[i][1]+1;
            if(j<n)
              pick+=dp[j];
          long long skip=dp[i+1];
          dp[i]=max(pick,skip);
        }
        return dp[0];
    }
};