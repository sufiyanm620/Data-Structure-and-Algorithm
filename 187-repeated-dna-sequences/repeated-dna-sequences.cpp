class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n=s.size();
        string res="";
        if(n<10) return ans;
        map<string,int> mp;
        for(int i=0;i<10;i++) res+=s[i];
        mp[res]++;
        for(int i=10;i<n;i++){
            res.erase(0,1);
            res+=s[i];
            mp[res]++;
        }
        for(auto &it:mp){
            if(it.second>1)
             ans.push_back(it.first);
        }
        return ans;
    }
};