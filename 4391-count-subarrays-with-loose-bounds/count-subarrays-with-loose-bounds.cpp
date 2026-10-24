class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=maxK&&nums[i]>=minK)
             ans+=i-j+1;
            else
            j=i+1;
            
        }
        return ans;
    }
};