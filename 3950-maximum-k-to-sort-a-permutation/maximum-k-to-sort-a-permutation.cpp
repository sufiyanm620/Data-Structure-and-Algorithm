class Solution {
public:
    int sortPermutation(vector<int>& nums) {
      int ans=0;
      int n=nums.size();
      bool check=false;
      for(int i=0;i<n;i++){
        if(nums[i]!=i&&!check){
          ans=nums[i];
          check=true;
        }
        if(check&&nums[i]!=i){
            ans&=nums[i];
        }
      }  
      return ans;
    }
};