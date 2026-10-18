class Solution {
public:
    bool dfs(int n,vector<vector<int>> &graph,int s,int d,vector<bool> &vis){
        if(s==d) return true;
        vis[s]=true;
        for(auto &v:graph[s]){
            if(!vis[v]){
            if(dfs(n,graph,v,d,vis))
              return true;
         }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> graph(n);
        for(auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        return dfs(n,graph,s,d,vis);
    }
};