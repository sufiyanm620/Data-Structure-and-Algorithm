class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int l=0;
        map<int,int> mp;
        for(int r=0;r<n;r++){
               mp[nums[r]]++;
               while(mp[nums[r]]==2){
                mp[nums[l]]--;
               
                 ans=min(ans,r-l+1);
                  l++;
               }
              
        }
        return ans==INT_MAX?-1:ans;
    }
};