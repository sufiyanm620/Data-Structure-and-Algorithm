class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
        queue<pair<int,int>> que;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    count++;
                    que.push({i,j});
                    while(!que.empty()){
                        auto [x,y]=que.front();
                        que.pop();
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&board[ni][nj]=='X'){
                                que.push({ni,nj});
                                board[ni][nj]='.';
                            }
                        }
                    }
                }
            }
        }
        return count;

    }
};