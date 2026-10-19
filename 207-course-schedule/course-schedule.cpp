class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
         vector<int> inDegree(n,0);
         unordered_map<int,vector<int>> adj;
         for(auto &it:pre){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            inDegree[it[1]]++;
         }
         queue<int> que;
         for(int i=0;i<n;i++){
            if(inDegree[i]==0)
              que.push(i);
         }
         int count=0;
         while(!que.empty()){
            int u=que.front();
            count++;
            que.pop();
            for(auto &v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0){
                  que.push(v);
            }
         }
    }
         return n==count;

    }
};