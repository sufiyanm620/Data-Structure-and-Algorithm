class Solution {
public:
    void solve(vector<string> &ans,string &res,int o,int c,int n){
       if(c==n){
        ans.push_back(res);
        
       }
       if(o<n){
       res.push_back('(');
       solve(ans,res,o+1,c,n);
       res.pop_back();
       }
       if(c<o){
        res.push_back(')');
        solve(ans,res,o,c+1,n);
        res.pop_back();
       }
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        solve(ans,res,0,0,n);
        return ans;
    }
};