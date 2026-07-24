class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1)&&(maze[i][j]=='.')&&(i!=entrance[0]||j!=entrance[1])){
                    que.push({i,j});
                    maze[i][j]='+';
                }
            }
        }
        if(que.empty()) return -1;
        int steps=0;
        while(!que.empty()){
            int k=que.size();
            while(k--){
            auto [x,y]=que.front();
            que.pop();
            if(x==entrance[0]&&y==entrance[1]) return steps;
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1]; 
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&maze[ni][nj]=='.'){
                    maze[ni][nj]='+';
                    que.push({ni,nj});
                }
            }
        }
        steps++;
        }
        return -1;
    }
};