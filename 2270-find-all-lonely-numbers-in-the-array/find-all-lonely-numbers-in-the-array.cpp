class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int x:nums) mp[x]++;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==1&&mp[nums[i]+1]==0&&mp[nums[i]-1]==0)
               ans.push_back(nums[i]); 
        }
        return ans;
    }
};