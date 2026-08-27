class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& grumpy, int k) {
      int n=nums.size();
      int ans=0;
      int maxx=0;
      for(int i=0;i<n;i++){
          if(grumpy[i]==0){
            ans+=nums[i];
            nums[i]=0;
          }
      }
      int sum=0;
      for(int i=0;i<k;i++){
        sum+=nums[i];
      }
      for(int i=k;i<n;i++){
        maxx=max(sum,maxx);
        sum+=nums[i];
        sum-=nums[i-k];
        
      }
      maxx=max(maxx,sum);
      return ans+maxx;
    }
};