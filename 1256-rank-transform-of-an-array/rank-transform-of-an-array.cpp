class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums;
        nums=arr;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i+1;
        }
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i]=mp[arr[i]];
        }
        return ans;


    }
};