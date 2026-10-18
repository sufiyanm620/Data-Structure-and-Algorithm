class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=LLONG_MAX;
        long long totalSum=0;
        for(int x:nums) totalSum+=x;
        for(int i=0;i<n;i++){
             long long cost=totalSum-1LL*nums[i]*(n-i);
             ans=min(ans,cost);
        }
        return ans;
    }
};