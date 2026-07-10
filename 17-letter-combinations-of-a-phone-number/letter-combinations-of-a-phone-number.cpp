class Solution {
public: 
    int n;
    void solve(string &digits,int idx,unordered_map<char,string>& mp,
    string &res,vector<string> &ans){
        if(idx==digits.size()){
            ans.push_back(res);
            return ;
        }
        char ch = digits[idx];
        string str=mp[ch];
        for(int i=0;i<str.size();i++){
            res.push_back(str[i]);
            solve(digits,idx+1,mp,res,ans);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         n = digits.size();
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string> ans;
        string res;
         solve(digits,0,mp,res,ans);
         return ans;
     }
};