class Solution {
public:
    void dfs(vector<vector<int>>& graph,int u,vector<bool>& vis){
        vis[u]=true;
        for(int v=0;v<graph.size();v++){
        if(!vis[v]&&graph[u][v]){
            dfs(graph,v,vis);
        }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis);
                count++;
            }
        }
        return count;
    }
};