class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n=nums.size();
       int num=0;
       if(n==1) return 0;
     
    //    if(n==2) return nums[0]!=nums[1]?2:0;
       unordered_map<int,int> mp;
         mp[0]=-1;
       int ans=0;
       for(int i=0;i<n;i++){
        if(nums[i]) num++;
        else num--;
        if(mp.find(num)!=mp.end())
          ans=max(ans,i-mp[num]);
        else
          mp[num]=i;
       }
       return ans;
    }
};