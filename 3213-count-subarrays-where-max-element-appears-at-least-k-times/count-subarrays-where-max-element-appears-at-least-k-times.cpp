class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    long long solve(vector<int>& nums, int k,int num){
        int l=0;
        long long ans=0;
        mp.clear();
          for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[num]>=k){
                ans+=n-i;
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                 mp.erase(nums[l]);
                   l++;
            }
          }
          return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        n=nums.size();
        int num=*max_element(nums.begin(),nums.end());
        return solve(nums,k,num);
    }
};