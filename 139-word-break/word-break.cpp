class Solution {
public:
    bool solve(string &s, vector<string>& wordDict,int prev,int i,unordered_map<string,int> &freq,vector<vector<int>> &dp){
        if(i>s.size()) return false;
        if(i==s.size()) return freq.count(s.substr(prev,i-prev));
       
        if(dp[prev][i]!=-1) return dp[prev][i];
        bool ans=false;
        if(freq.count(s.substr(prev,i-prev+1)))
            ans=ans||solve(s,wordDict,i+1,i+1,freq,dp);
         ans=ans||solve(s,wordDict,prev,i+1,freq,dp);
         return dp[prev][i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> freq;
        for(auto &st : wordDict) freq[st]++;
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,wordDict,0,0,freq,dp);
    }
};