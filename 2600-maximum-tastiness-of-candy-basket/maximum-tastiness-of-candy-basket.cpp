class Solution {
public:
    int n;
    bool isPossible(vector<int>& nums, int k,int mid){
        int f=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]-f>=mid){
                count++;
                f=nums[i];
            }
        }
        return count>=k;
    }
    int maximumTastiness(vector<int>& nums, int k) {
      n=nums.size();
      sort(nums.begin(),nums.end());
      int l=0;
      int ans=-1;
      int r=*max_element(nums.begin(),nums.end());
      while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
      }
      return ans;
    }
};