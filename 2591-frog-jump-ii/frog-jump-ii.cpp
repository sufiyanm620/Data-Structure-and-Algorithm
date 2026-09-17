class Solution {
public:
    int maxJump(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n==2) return nums[1]-nums[0]; 
        for(int i=2;i<n;i+=2){
            ans=max(ans,nums[i]-nums[i-2]);
        }
        for(int i=3;i<n;i+=2){
            ans=max(ans,nums[i]-nums[i-2]);
        }
        return ans;
    }
};