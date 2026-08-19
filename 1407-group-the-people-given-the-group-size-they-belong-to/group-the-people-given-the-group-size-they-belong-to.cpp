class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()==nums[i]){
              ans.push_back(mp[nums[i]]);
              mp[nums[i]].clear();
            }
        }
        return ans;
    }
};