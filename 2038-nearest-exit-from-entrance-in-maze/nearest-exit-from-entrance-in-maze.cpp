class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j]=='+')
                grid[i][j]=1;
            }
        }
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        queue<vector<int>> que;
        int steps=0;
        que.push({entrance[0],entrance[1],0});
        while(!que.empty()){
            auto curr=que.front();
            int x=curr[0];
            int y=curr[1];
            int steps=curr[2];
            que.pop();
            maze[entrance[0]][entrance[1]]=1;
            if((x!=entrance[0]||y!=entrance[1])&&(x==0||y==0||x==m-1||y==n-1))
               return steps;
            for(auto &dir:directions){
                int ni=x+dir[0];
                int nj=y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==0){
                    que.push({ni,nj,steps+1});
                    grid[ni][nj]=1;
                }
            }
        }
        return -1;
    }
};