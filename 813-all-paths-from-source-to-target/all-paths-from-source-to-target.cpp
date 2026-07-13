class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& graph,int u,vector<vector<int>>& ans,
    vector<int>& path){
        if(u==n-1){
            ans.push_back(path);
            return;
        }
        for(auto &v:graph[u]){
            path.push_back(v);
            dfs(graph,v,ans,path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
         n=graph.size();
         path.push_back(0);
        dfs(graph,0,ans,path);
        return ans;
    }
};