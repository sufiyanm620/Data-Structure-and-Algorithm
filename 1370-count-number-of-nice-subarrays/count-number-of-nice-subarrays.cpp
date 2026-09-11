class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n=nums.size();
        int count=0;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]%2)
              count++;
              while(count>=k){
                    ans+=n-r;
                    if(nums[l]%2) count--;
                    l++;
              }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return solve(nums,k)-solve(nums,k+1);
    }
};