class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m!=n) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char c:word1) mp1[c]++;
        for(char c:word2) mp2[c]++;
        if(mp1.size()!=mp2.size()) return false;
        for(auto &[ch,freq]:mp1){
            if(!mp2.count(ch)) return false;
        }
        vector<int> res1,res2;
        for(auto &it:mp1) res1.push_back(it.second);
        for(auto &it:mp2) res2.push_back(it.second);
        sort(res1.begin(),res1.end());
        sort(res2.begin(),res2.end());
        return res1==res2;
    }
};