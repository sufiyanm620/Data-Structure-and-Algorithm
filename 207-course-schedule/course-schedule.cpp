class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &it:prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            count++;
            for(auto &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        return count==n;
    }
};