class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c++;
                ans+=c;
            }else{
                c=0;
            }
        }
        return ans;
    }
};