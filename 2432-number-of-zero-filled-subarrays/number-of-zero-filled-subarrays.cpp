class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int c=0;
        int n=nums.size();
        for(int x:nums){
            if(x==0){
                c++;
                ans+=c;
            }else c=0;
        }
        return ans;
    }
};