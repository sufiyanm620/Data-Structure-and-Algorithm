class Solution {
public:
   
    // void dfs(int u,int prev,unordered_map<int,vector<int>> adj, vector<int> ans){
    //     ans.push_back(u);
    //     for(auto &v:adj[u]){
    //         if(v!=prev){
    //             dfs(v,u,adj,ans);
    //         }
    //     }
    // }
    vector<int> restoreArray(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> degree;
        for(auto &it:graph){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        int u;
        for(auto &it:degree){
             if(it.second==1){
                u=it.first;
                break;
             }
        }
         vector<int> ans;
         int prev=INT_MIN;
         int curr=u;
         while(true){
            ans.push_back(curr);
            int next=INT_MIN;
            for(auto &v:adj[curr]){
                if(v!=prev){
                    next=v;
                    break;
                }
            }
            if(next==INT_MIN) break;
            prev=curr;
            curr=next;
         }
      return ans;
    }
};