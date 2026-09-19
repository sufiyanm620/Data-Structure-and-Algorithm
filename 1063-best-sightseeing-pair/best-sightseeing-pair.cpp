class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int maxx=nums[0]+0;
        for(int i=1;i<n;i++){
           ans=max(ans,nums[i]+maxx-i);
           maxx=max(maxx,nums[i]+i);
        } 
        return ans;
    }
};