class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=curr[0];
            int u=curr[1];
            pq.pop();
            if(wt>dist[u]) continue;
            if(u==n-1) return dist[u];
            for(auto &v:adj[u]){
                int node=v.first;
                int cost=v.second;
                if(cost+dist[u]<dist[node]){
                    dist[node]=cost+dist[u];
                    pq.push({dist[node],node});
                }
            }
        }
        return -1;
    }
};