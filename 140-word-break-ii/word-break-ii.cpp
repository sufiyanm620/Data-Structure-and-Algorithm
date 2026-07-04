class Solution {
public:
    vector<string> solve(unordered_map<string,int>& freq,string &s,int prev,vector<vector<string>>& dp,vector<bool> &vis){
        if(prev==s.size()) return {""};
        if(vis[prev]) return dp[prev];
        vis[prev]=true;
        vector<string> ans;
        for(int i=prev+1;i<=s.size();i++){
             string word=s.substr(prev,i-prev);
             if(freq.count(word)){
                auto suffixes = solve(freq,s,i,dp,vis);
                for(auto &suffix:suffixes){
                    if(suffix == "")
                        ans.push_back(word);
                    else
                        ans.push_back(word+" "+suffix);
                }
             }
        }
        return dp[prev]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> freq;
        for(string &s:wordDict) freq[s]++;
        int n=s.size();
         vector<vector<string>> dp(n+1);
         vector<bool> vis(n+1,false);
         return solve(freq,s,0,dp,vis);
    }
};