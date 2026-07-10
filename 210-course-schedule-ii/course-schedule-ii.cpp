class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(num,0);
        vector<int> ans;
        for(auto &it:graph){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        } 
        queue<int> que;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
              que.push(i);
            }
        }
        while(!que.empty()){
            int u=que.front();
            ans.push_back(u);
            que.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)
                   que.push(v);
            }
        }
       reverse(ans.begin(),ans.end());
        if(ans.size()==num){
            return ans;
        }
        return {};
    }
};