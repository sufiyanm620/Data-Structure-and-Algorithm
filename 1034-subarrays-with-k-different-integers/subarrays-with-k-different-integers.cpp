class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp,freq;
        int n=nums.size();
        int ans=0;
        int r=0;
        int i=0;
        for(int j=0;j<n;j++){
             mp[nums[j]]++;
             while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                mp.erase(nums[i]);
                i++;
                r=0;
             }
             while(mp.size()==k&&mp[nums[i]]>1){
                mp[nums[i]]--;
                i++;
                r++;
             }
             if(mp.size()==k)
             ans+=r+1;
        }
        return ans;
    }
};