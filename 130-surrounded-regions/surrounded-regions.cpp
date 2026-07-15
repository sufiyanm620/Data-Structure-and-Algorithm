class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,int> p;
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<p> que;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
              board[i][0]='#';
              que.push({i,0});
            }
            if(board[i][n-1]=='O'){
                board[i][n-1]='#';
                que.push({i,n-1});
            }
        }
        for(int j=1;j<n-1;j++){
            if(board[0][j]=='O'){
                board[0][j]='#';
                que.push({0,j});
            }
            if(board[m-1][j]=='O'){
                board[m-1][j]='#';
                que.push({m-1,j});
            }
        }
        while(!que.empty()){
            p curr=que.front();
            int x = curr.first;
            int y = curr.second;
            que.pop();
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&board[ni][nj]=='O'){
                          board[ni][nj]='#';
                          que.push({ni,nj});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='#')
                   board[i][j]='X';
                else 
                    board[i][j]='O';
            }
        }
    }
};