class Solution {
public:
    typedef pair<int,int> p;
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<p>> adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        } 
        vector<int> arr(n);
        for(int i=0;i<n;i++){
        vector<int> dist(n,INT_MAX); 
        priority_queue<p,vector<p>,greater<p>> pq;
        dist[i]=0;
        pq.push({0,i});
        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();
            // if(cost>dist[u]) continue;
            for(auto &it:adj[u]){
                int v=it.first;
                int wt=it.second;
                if(wt+dist[u]<dist[v]){
                    dist[v]=wt+dist[u];
                    pq.push({dist[v],v});
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dist[i]<=t)
                count++;
        }
        arr[i]=count-1;
        }
      
        int city=-1;
        int reached=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<=reached){
                reached=arr[i];
                city=i;
            }
        }
        return city;
    }
};