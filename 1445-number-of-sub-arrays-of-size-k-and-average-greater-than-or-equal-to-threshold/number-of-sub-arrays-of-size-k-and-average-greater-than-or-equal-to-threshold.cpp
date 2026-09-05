class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int t) {
        int n=nums.size();
        int ans=0;
        long long sum=0;
        for(int i=0;i<k;i++) sum+=nums[i];
        if(1.0*sum/k>=t) ans++;
        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            if(1.0*sum/k>=t) ans++;
        }
        return ans;
    }
};