class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int sum=0;
        int ans = INT_MAX;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[l];
                     ans=min(ans,r-l+1);
                    l++;
                   
                }
              
            }
        }
        return ans==INT_MAX?0:ans;

    }
};