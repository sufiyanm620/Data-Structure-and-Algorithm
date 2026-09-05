class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        if(n==1) return 0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1])
                   return 0;
                else{
                 l=mid+1;
                 continue;
                }
            }
            if(mid==n-1){
                if(nums[mid]>nums[mid-1]) return n-1;
                else{
                 r=mid-1;
                 continue;
                }
            }
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]<nums[mid+1])
              l=mid+1;
            else 
              r=mid-1;
        }
        return -1;
    }
};