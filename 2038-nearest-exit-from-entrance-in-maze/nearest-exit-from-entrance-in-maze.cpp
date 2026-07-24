class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> directions{{1,0},{0,1},{0,-1},{-1,0}};
        queue<pair<int,int>> que;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!que.empty()){
            int k=que.size();
            while(k--){
                auto [x,y]=que.front();
                que.pop(); 
                for(auto &dir:directions){
                    int ni=x+dir[0];
                    int nj=y+dir[1];
                    if(ni>=0&&nj>=0&&ni<m&&nj<n&&maze[ni][nj]=='.'){
                         if(ni==0||nj==0||ni==m-1||nj==n-1&&(maze[ni][nj]=='.')) return steps+1;
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