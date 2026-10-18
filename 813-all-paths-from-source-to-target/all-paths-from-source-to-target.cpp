class Solution {
public:
    int n;
    void solve(vector<vector<int>>& graph,int u,vector<int>& res,vector<vector<int>>& ans){
        if(u==n-1){
            ans.push_back(res);
            return ;
        }
        for(auto &v:graph[u]){
            res.push_back(v);
            solve(graph,v,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> res;
        vector<vector<int>> ans;
        res.push_back(0);
        solve(graph,0,res,ans);
        return ans;
    }
};