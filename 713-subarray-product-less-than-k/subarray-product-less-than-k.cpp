class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int prod=1;
        int l=0;
        int ans=0;
        if(k==1||k==0) return 0;
        for(int r=0;r<n;r++){
            prod*=nums[r];
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};