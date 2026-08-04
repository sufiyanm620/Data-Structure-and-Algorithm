class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int x:nums) mp[x]++;
        int minn=*min_element(nums.begin(),nums.end());
        int maxx=*max_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=minn+1;i<maxx;i++){
            if(mp[i]<1)
              ans.push_back(i);
        }
        return ans;
    }
};