class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        map<int,int> mp;
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        if(mp.size()==k) ans=sum;
        for(int i=k;i<n;i++){
                sum+=nums[i];
                sum-=nums[i-k];
                mp[nums[i]]++;
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0)
                 mp.erase(nums[i-k]);
                if(mp.size()==k)
                 ans=max(ans,sum);
        }
        return ans;
    }
};