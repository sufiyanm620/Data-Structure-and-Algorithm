class Solution {
public:
   bool dfs(int u,int target,unordered_map<int,vector<int>> &adj,vector<int> &vis){
    vis[u]=1;
    if(u==target) return true;
    for(auto &v:adj[u]){
        if(!vis[v]){
          if(dfs(v,target,adj,vis)) return true;
    }
    }
    return false;
   }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto &it:pre){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
              vector<int> vis(n,0);
              if(dfs(queries[i][0],queries[i][1],adj,vis))
              ans.push_back(true);
              else
            ans.push_back(false);
        }
        return ans;
    }
};