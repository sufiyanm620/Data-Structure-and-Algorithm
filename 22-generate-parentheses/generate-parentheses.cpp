class Solution {
public:
    vector<string> ans;
    void solve(string res,int n,int o,int c){
        if(c==n){
              ans.push_back(res);
              return;
        }
        if(o<n){
            res.push_back('(');
            solve(res,n,o+1,c);
            res.pop_back();
        }
        if(c<o){
            res.push_back(')');
            solve(res,n,o,c+1);
            res.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string res="";
        solve(res,n,0,0);
        return ans;
    }
};