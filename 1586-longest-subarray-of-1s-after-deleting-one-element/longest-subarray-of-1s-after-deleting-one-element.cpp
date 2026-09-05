class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) count--;
            while(count<0){
                if(nums[l]==0)
                  count++;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans-1;
    }
};