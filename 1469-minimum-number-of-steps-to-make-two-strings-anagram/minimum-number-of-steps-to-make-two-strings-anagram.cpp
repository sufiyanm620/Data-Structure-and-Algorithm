class Solution {
public:
    int minSteps(string s, string t) {
        int count=0;
        int n=s.size();
        unordered_map<int,int> mp;
        for(auto &it:t) mp[it]++;
        for(char c:s){
            if(mp[c]>0){
                mp[c]--;   
            }else count++;
        }
        return count;
    }
};