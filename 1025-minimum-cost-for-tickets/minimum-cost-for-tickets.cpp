class Solution {
public:
    int n;
    int find(vector<int>& nums, int i, int d) {
        int j = i;
        while(j<n&&nums[j]<nums[i]+d) {
            j++;
        }
         return j;
    }
    int solve(vector<int>& nums, vector<int>& costs,int i,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take1=INT_MAX;;
        take1=costs[0]+solve(nums,costs,i+1,dp);
        int take7=find(nums,i,7);
        take7=costs[1]+solve(nums,costs,take7,dp);
        int take30=find(nums,i,30);
        take30=costs[2]+solve(nums,costs,take30,dp);
        return dp[i]=min({take1,take7,take30});
    }
    int mincostTickets(vector<int>& nums, vector<int>& costs) {
        n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,costs,0,dp);
    }
};