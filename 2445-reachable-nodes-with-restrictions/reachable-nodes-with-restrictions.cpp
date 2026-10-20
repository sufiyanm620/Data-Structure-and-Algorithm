class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        unordered_map<int,vector<int>> adj;
          vector<bool> vis(n,false);
        for(auto &it:edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        vis[0]=true;
        queue<int> que;
        que.push(0);
        vector<bool> rest(n,false);
        for(int i=0;i<res.size();i++){
                   int k=res[i];
                   rest[k]=true;
        }
        int count=0;
        while(!que.empty()){
            int sz=que.size();
            while(sz--){
                   count++;
            auto curr=que.front();
            que.pop();
            
            for(auto &v:adj[curr]){
                if(!vis[v]&&!rest[v]){
                    que.push(v);
                    vis[v]=true;
                }
            }
        }
     
        }
     
        return count;
    }
};