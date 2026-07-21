class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& graph) {
         vector<int> indegree(num,0);
         int m=graph.size();
         unordered_map<int,vector<int>> adj;
         for(int i=0;i<m;i++){
               int u=graph[i][0];
               int v=graph[i][1];
               adj[u].push_back(v);
               indegree[v]++;
         }
         queue<int> que;
         for(int i=0;i<num;i++){
               if(indegree[i]==0)
                 que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int u=que.front();
            que.pop();
            count++;
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)
                  que.push(v);
            
        }
        }
        return count==num;
    }

};