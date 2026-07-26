class Solution {
public:
    int n;
    pair<int,int> getCoordinates(int num){
        int rt = (num-1)/n;
        int rb = n-1-rt;
        int col = (num-1)%n;
        if((n%2==0&&rb%2==0)||(n%2==1&&rb%2==1)) 
          col=(n-1)-col;
          return make_pair(rb,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
      this->n=board.size();
       vector<vector<bool>> vis(n,vector<bool>(n,0));
       queue<int> que;
       int count=0;
       que.push(1);
       while(!que.empty()){
        int sz=que.size();
        while(sz--){
            int m=que.front();
            que.pop();
            if(m==n*n) return count;
            for(int i=1;i<=6;i++){
                int val=m+i;
                if(val>n*n)
                   break;
                pair<int,int> p = getCoordinates(val);
                int r=p.first;
                int c=p.second;
                if(vis[r][c]) continue;
                vis[r][c]=true;
                if(board[r][c]==-1)
                  que.push(val);
                else 
                  que.push(board[r][c]);
            }
        }
        count++;
       }
       return -1;
    }
};