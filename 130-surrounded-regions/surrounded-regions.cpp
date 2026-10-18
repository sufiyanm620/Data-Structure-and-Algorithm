class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1)&&board[i][j]=='O'){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    vis[i][j]=1;
                    while(!que.empty()){
                        auto [x,y]=que.front();
                        que.pop();
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&board[ni][nj]=='O'&&!vis[ni][nj]){
                                vis[ni][nj]=1;
                                que.push({ni,nj});
                            }
                        }

                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&!vis[i][j])
                  board[i][j]='X';
            }
        }
    }
};