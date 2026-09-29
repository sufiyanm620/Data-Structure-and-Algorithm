class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int last=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
           int val=max(nums[i]-k,last+1);
           if(val<=nums[i]+k){
            count++;
            last=val;
           }
        }
        return count;
    }
};