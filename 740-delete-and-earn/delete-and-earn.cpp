class Solution {
public:
    int m;
    vector<int> dp;
    int solve(int i,vector<int>& arr){
        if(i>=m) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=arr[i]+solve(i+2,arr);
        int skip=solve(i+1,arr);
        return dp[i]=max(pick,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
        dp.resize(maxx+1,-1);
        m=maxx+1;
        int n=nums.size();
        vector<int> arr(maxx+1,0);
        for(int i=0;i<n;i++)
          arr[nums[i]]+=nums[i];
        return solve(0,arr);
    }
};