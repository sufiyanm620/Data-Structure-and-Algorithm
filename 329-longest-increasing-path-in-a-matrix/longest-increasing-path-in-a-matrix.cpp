class Solution {
public:
    typedef pair<int,int> p;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> indegree(m,vector<int>(n,0));
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto &dir:directions){
                    int ni = i+dir[0];
                    int nj = j+dir[1];
                    if(ni>=0&&nj>=0&&ni<m&&nj<n&&matrix[ni][nj]>matrix[i][j]){
                        indegree[ni][nj]++;
                    }
                }
            }
        }
        queue<p> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(indegree[i][j]==0){
                    que.push({i,j});
                }
            }
        }
         int ans=0;
         while(!que.empty()){
            int k = que.size();
            ans++;
            while(k--){
            p curr = que.front();
            int x = curr.first;
            int y = curr.second;
            que.pop();
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&matrix[ni][nj]>matrix[x][y]){
                    indegree[ni][nj]--;
                    if(indegree[ni][nj]==0){
                    que.push({ni,nj});
                    }
                }
            }
         }
         }
        return ans;
            
    }
};