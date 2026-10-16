class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void solve(int i,int n,int k){
      if(res.size()==k){
        ans.push_back(res);
        return;
      }
      for(int j=i;j<=n;j++){
          res.push_back(j);
          solve(j+1,n,k);
          res.pop_back();
      }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1,n,k);
        return ans;
    }
};