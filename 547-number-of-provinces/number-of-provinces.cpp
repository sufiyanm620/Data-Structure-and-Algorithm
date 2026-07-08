class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected,int u,vector<bool> &vis){
        vis[u]=true;
        for(int i=0;i<n;i++){
            if(isConnected[u][i]&&!vis[i]){
                dfs(isConnected,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         n = isConnected.size();
         int provinces=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,i,vis);
                provinces++;
            }
        }
        return provinces;

    }
};