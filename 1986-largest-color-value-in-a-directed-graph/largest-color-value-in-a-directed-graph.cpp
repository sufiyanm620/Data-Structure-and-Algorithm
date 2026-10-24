class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int n=colors.size();
        vector<int> inDegree(n,0);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> que;
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
             que.push(i);
             dp[i][colors[i]-'a']=1;
        }
        int ans=0;
        int count=0;
        while(!que.empty()){
            auto curr=que.front();
            que.pop();
            count++;
            ans=max(ans,dp[curr][colors[curr]-'a']);
            for(auto &v:adj[curr]){
                for(int i=0;i<26;i++){
                    dp[v][i]=max(dp[v][i],dp[curr][i]+(colors[v]-'a'==i));
                }
                inDegree[v]--;
                if(inDegree[v]==0)
                 que.push(v);
            }

        }
       return count==n?ans:-1;

    }
};