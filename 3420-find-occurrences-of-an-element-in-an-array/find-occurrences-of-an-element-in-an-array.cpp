class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
         vector<int> pos;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x)
             pos.push_back(i);
        }
        vector<int> ans;
        for(int q:queries){
            if(q<=pos.size())
              ans.push_back(pos[q-1]);
            else 
              ans.push_back(-1);
        }
        return ans;
    }
};