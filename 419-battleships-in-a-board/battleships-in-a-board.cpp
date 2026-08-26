class Solution {
public:
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    int m;
    int n;
    void dfs(int i,int j,vector<vector<char>> &board){
        board[i][j]='.';
        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            if(ni<0||nj<0||ni>=m||nj>=n) continue;
            if(board[ni][nj]=='X')
              dfs(ni,nj,board);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
         m=board.size();
         n=board[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    count++;
                    dfs(i,j,board);
                }
            }
        }
        return count;

    }
};