class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         vector<int> arr;
         arr=nums;
         sort(nums.begin(),nums.end());
          if(nums==arr) return 0;
         int n=nums.size();
         int l=0;
         int r=n-1;
         for(int i=0;i<n;i++){
            if(arr[i]!=nums[i]){
                l=i;
                break;
            }
         }
         for(int i=n-1;i>=l;i--){
            if(arr[i]!=nums[i]){
                r=i;
                break;
            }

         }
        
         return r-l+1;

    }
};