class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int maxx=INT_MIN;
            int minn=INT_MAX;
            for(int j=i;j<n;j++){
                if(nums[j]<minn) minn=nums[j];
                if(nums[j]>maxx) maxx=nums[j];
                ans=ans+maxx-minn;
            }
        }
        return ans;
    }
};