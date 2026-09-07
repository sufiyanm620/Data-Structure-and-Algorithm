class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        for(int x:nums){
            if(x) count1++;
        }
        int count=0;
        for(int i=0;i<count1;i++){
            if(nums[i]) count++;
        }
        int ans=count;
        for(int i=count1;i<n+count1;i++){
            if(nums[(i-count1)%n]) count--;
            if(nums[i%n]) count++;
            ans=max(ans,count);
        }
        return count1-ans;

    }
};