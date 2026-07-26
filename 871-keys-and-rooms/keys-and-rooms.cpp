class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int> que;
        que.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            adj[i]=rooms[i];
        }
        unordered_map<int,vector<int>> mp;
        while(!que.empty()){
            int u=que.front();
            que.pop();
             for(auto &v:adj[u]){
                if(!vis[v]){
                que.push(v);
                vis[v]=true;
                }
             }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};