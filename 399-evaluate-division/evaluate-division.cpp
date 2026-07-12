class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> &adj,string u,string v,unordered_set<string>& vis,double mult,double &ans){
        if(vis.count(u)) return;
        vis.insert(u);
        if(u==v){
            ans=mult;
            return;
        }
        for(auto &it : adj[u]){
            string m=it.first;
            double val=it.second;
            dfs(adj,m,v,vis,mult*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size();
        int n = queries.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<m;i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double val = values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        vector<double> res;
        for(auto &it : queries){
            string u = it[0];
            string v = it[1];
            double ans = -1.0;
            double mult = 1.0;
            if(adj.count(u)){
                unordered_set<string> vis;
                dfs(adj,u,v,vis,mult,ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};