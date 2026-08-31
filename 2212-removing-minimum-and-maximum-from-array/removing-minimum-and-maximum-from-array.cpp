class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx=0;
        int maxIdx=0;
        int minn=*min_element(nums.begin(),nums.end());
        int maxx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==maxx) maxIdx=i+1;
            if(nums[i]==minn) minIdx=i+1;
        }
        int x=min(maxIdx,minIdx);
        int y=max(maxIdx,minIdx);
        int a=x+(n+1-y);
        return min({y,n-x+1,a});
    }
};