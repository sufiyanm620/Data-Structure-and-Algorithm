class Solution {
public:
    int findGCD(vector<int>& nums) {
        int i,max=INT_MIN,min=INT_MAX,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
                 max=nums[i];
            if(nums[i]<min)
                 min=nums[i];
        }
        for(int j=1;j<=min;j++){
            if(max%j==0&&min%j==0)
                 ans=j;
        }
        return ans;
    }
};