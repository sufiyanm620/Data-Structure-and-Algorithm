class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans==0?*max_element(nums.begin(),nums.end()):ans;
    }
};