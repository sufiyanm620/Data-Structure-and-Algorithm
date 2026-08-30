class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto &it:intervals){
            int l=it[0];
            int r=it[1];
            mp[l]+=1;
            mp[r+1]-=1;
        }
        int ans=0;
        int sum=0;
        for(auto &it:mp){
            sum+=it.second;
             ans=max(ans,sum);
        }
        return ans;

    }
};