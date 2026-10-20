class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums,int i,int k){
        if(i==n||k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int skip=solve(nums,i+1,k);
        int l=i+1;
        int r=n-1;
        int next=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid][0]>nums[i][1]){
                  next=mid;
                  r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int pick=nums[i][2]+solve(nums,next,k-1);
        return dp[i][k]=max(pick,skip);
    }
    int maxTwoEvents(vector<vector<int>>&  nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        dp.resize(n,vector<int>(3,-1));
        return solve(nums,0,2);
    }
};