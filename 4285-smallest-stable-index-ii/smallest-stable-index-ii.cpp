class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums1(n);
        vector<int> nums2(n);
        int maxx = INT_MIN;
        int minn = INT_MAX;
        for(int i=0;i<n;i++){
            maxx = max(maxx,nums[i]);
            nums1[i]=maxx;
        }
        for(int i=n-1;i>=0;i--){
            minn = min(minn,nums[i]);
            nums2[i]=minn;
        }
        for(int i=0;i<n;i++){
            if(nums1[i]-nums2[i]<=k){
                  return i;
            }
        }
        return -1;
    }
};