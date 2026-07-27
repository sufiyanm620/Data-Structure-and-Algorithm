class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = LLONG_MIN;
        int n=nums.size();
        vector<long long> suff(n);
        vector<long long> pref(n);
        suff[n-1]=nums[n-1];
        pref[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=max(1LL*nums[i],suff[i+1]);
            pref[i]=min(1LL*nums[i],pref[i+1]);
        }
        for(int i=0;i+m-1<n;i++){
                ans=max(ans,1LL*nums[i]*suff[i+m-1]);
                ans=max(ans,1LL*nums[i]*pref[i+m-1]);
            
        }
        return ans;
    }
};