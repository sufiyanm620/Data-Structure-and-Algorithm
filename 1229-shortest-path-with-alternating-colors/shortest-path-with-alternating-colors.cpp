class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adj1(n),adj2(n);
        for(auto &it:redEdges) adj1[it[0]].push_back(it[1]);
        for(auto &it:blueEdges) adj2[it[0]].push_back(it[1]);
        vector<vector<int>> dist(n,vector<int>(2,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        dist[0][0]=0;
        dist[0][1]=0;
        pq.push({0,0,0});
        pq.push({0,0,1});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int wt=curr[0];
            int u=curr[1];
            int color=curr[2];
            if(wt>dist[u][color]) continue;
            if(color==0){
            for(auto &v:adj1[u]){
                    if(wt+1<dist[v][1]){
                        dist[v][1]=wt+1;
                        pq.push({dist[v][1],v,1});
                }
            }
            }else{
                for(auto &v:adj2[u]){
                    if(wt+1<dist[v][0]){
                        dist[v][0]=wt+1;
                        pq.push({dist[v][0],v,0});
                    }
                }
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int d=min(dist[i][0],dist[i][1]);
            ans[i]=(d==INT_MAX?-1:d);
        }
        return ans;



    }
};