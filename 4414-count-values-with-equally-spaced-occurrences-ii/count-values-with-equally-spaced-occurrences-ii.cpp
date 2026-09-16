class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq,last,diff;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            freq[x]++;
            if(freq[x]==1){
                last[x]=i;
            }
            else if(freq[x]==2){
                diff[x]=i-last[x];
                last[x]=i;
            }
            else{
                if(i-last[x]!=diff[x]) 
                  diff[x]=-1;
                else
                  last[x]=i;
            }
      }
      for(auto &it:freq){
         if(it.second>2&&diff[it.first]!=-1) ans++;
      }
      return ans;
    }
};