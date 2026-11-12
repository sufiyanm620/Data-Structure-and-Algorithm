class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int n=nums.size();
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                 inc++;
                ans=max(ans,inc);
                dec=1;
            }
            else if(nums[i]<nums[i-1]){
                dec++;
                ans=max(ans,dec);
                inc=1; 
            }
            else{
                ans=max({ans,inc,dec});
                inc=1;
                dec=1;
            }
        }
        return max({ans,inc,dec});

    }
};