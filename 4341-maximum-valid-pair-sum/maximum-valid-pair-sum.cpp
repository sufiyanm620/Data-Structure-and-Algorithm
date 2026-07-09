class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
           suff[i]=max(suff[i+1],nums[i]);
        }
        int ans = INT_MIN;
        for(int i=0;i+k<n;i++){
            ans=max(ans,nums[i]+suff[i+k]);
        }
        return ans;
    }
};