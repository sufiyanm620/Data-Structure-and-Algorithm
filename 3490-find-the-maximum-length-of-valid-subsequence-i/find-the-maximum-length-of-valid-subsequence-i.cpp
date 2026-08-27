class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        int zeroes=0;
        int count=1;
        int prev=nums[0]%2;
        for(int i=0;i<n;i++){
              nums[i]%=2;
              if(nums[i]%2==1) ones++;
              else zeroes++;
              if(nums[i]!=prev){
                count++;
                prev=nums[i];
              }
        }
        return max({ones,zeroes,count});
    }
};