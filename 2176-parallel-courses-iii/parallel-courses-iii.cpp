class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size();
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(int i=0;i<m;i++){
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> que;
        vector<int> maxTime(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
              que.push(i);
              maxTime[i]=time[i];
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto &v:adj[u]){
                maxTime[v]=max(maxTime[v],maxTime[u]+time[v]);
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
       int ans = *max_element(maxTime.begin(),maxTime.end());
       return ans;
        
    }
};