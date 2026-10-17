class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int k=INT_MIN;
        int l=INT_MIN;
        int sum=0;
        int last=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target&&nums[i]>nums[j]){
                    sum=nums[i]*nums[j];
                    if(sum>last){
                        last=sum;
                        k=i;
                        l=j;
                    }
                }
                else if(nums[i]+nums[j]==target&&nums[i]<nums[j]){
                    sum=nums[i]*nums[j];
                    if(sum>last){
                        last=sum;
                        k=j;
                        l=i;
                    }
                }
                 
            }
        }
         if(l==INT_MIN&&k==INT_MIN)
              return {-1,-1};
        return {k,l};
    }
};