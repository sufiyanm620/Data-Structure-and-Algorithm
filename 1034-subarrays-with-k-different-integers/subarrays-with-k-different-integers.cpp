class Solution {
public:
    int n;
   
    long long helper(vector<int>& nums, int k){
        map<int,int> mp;
        int l=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>=k){
                ans+=n-i;
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                  mp.erase(nums[l]);
                l++;
            }
            
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n=nums.size();
        return helper(nums,k)-helper(nums,k+1);
    }
};