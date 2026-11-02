class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    queue<vector<int>> que;
                    char c=grid[i][j];
                    que.push({i,j,-1,-1});
                    vis[i][j]=true;
                    while(!que.empty()){
                        int sz=que.size();
                        while(sz--){
                            auto curr=que.front();
                            int x=curr[0];
                            int y=curr[1];
                            int px=curr[2];
                            int py=curr[3];
                            que.pop();
                            for(auto &d:dir){
                                int ni=x+d[0];
                                int nj=y+d[1];
                                if(ni<0||nj<0||ni>=m||nj>=n) continue;
                                if(grid[ni][nj]!=c) continue;
                                if(ni==px&&nj==py) continue;
                                if(vis[ni][nj]) return true;
                                que.push({ni,nj,x,y});
                                vis[ni][nj]=true;
                                }
                            }
                        }
                    }
                }
            }
        
        return false;

    }
};