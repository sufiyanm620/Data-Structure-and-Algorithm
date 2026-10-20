class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int conn=0;
                int nodes=0;
                queue<int> que;
                que.push(i);
               
                vis[i]=true;
                while(!que.empty()){
                    auto &curr=que.front();
                    que.pop();
                    nodes++;
                    conn+=adj[curr].size();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
        int edgeCount=conn/2;
        if(edgeCount==nodes*(nodes-1)/2) count++;
        }
     }
        return count;
    }
};