class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[src][0]=0;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int wt=curr[0];
            int u=curr[1];
            int s=curr[2];
            if(u==dst) return wt;
            if(s==k+1) continue;
            for(auto &it:adj[u]){
                 int v=it.first;
                 int cost=it.second;
                 if(cost+wt<dist[v][s+1]){
                    dist[v][s+1]=cost+wt;
                    pq.push({cost+wt,v,s+1});
                 }
            }

        }
        return -1;
        
    }
};