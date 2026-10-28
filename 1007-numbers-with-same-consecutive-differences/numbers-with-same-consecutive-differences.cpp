class Solution {
public:
    string s="0123456789";
    void solve(int n,int k,string res,vector<string> &ans){
        if(res.size()>n) return;
        if(res.size()==n){
            ans.push_back(res);
            return;
        }
        for(char c:s){
            if(res.empty()&&c!='0'){
                res.push_back(c);
                solve(n,k,res,ans);
                res.pop_back();
            }
            else if(!res.empty()){
                if(abs(c-res.back())==k){
                    res.push_back(c);
                    solve(n,k,res,ans);
                    res.pop_back();
                }
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<string> ans;
        string res="";
        solve(n,k,res,ans);
        vector<int> ansr;
        for(string s:ans){
            int num=0;
            for(char c:s){
                num=num*10+c-'0';
            }
            ansr.push_back(num);
        }
        return ansr;
    }
};