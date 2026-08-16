class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int l=nums[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i][0]<l){
                count++;
            }else{
                l=nums[i][1];
            }
        }
        return count;
    }
};