class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(i==0||nums[i]!=nums[i-1])
              mp[nums[i]]++;
        }
        int ans=0;
        for(auto [x,count]:mp){
            if(count==1) ans++;
        }
        return ans;
    }
};