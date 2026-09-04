class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> dir{{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((board[i][j]=='O')&&(i==0||j==0||i==m-1||j==n-1)){
                    queue<pair<int,int>> que;
                    vis[i][j]=1;
                    que.push({i,j});
                    while(!que.empty()){
                        int sz=que.size();
                        while(sz--){
                            auto [r,c]=que.front();
                            que.pop();
                            for(auto &d:dir){
                                int nr=r+d[0];
                                int nc=c+d[1];
                                if(nr>=0&&nc>=0&&nr<m&&nc<n&&board[nr][nc]=='O'&&!vis[nr][nc]){
                                    vis[nr][nc]=1;
                                    que.push({nr,nc});
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j])
                  board[i][j]='X';
            }
        }
        
    }
};