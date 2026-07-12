class Solution {
public:
    typedef pair<int,int> p;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        int maxx = 0;
        int size=0;
        queue<p> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                     size=1;
                     que.push({i,j});
                     grid[i][j]=0;
                     while(!que.empty()){
                            p curr=que.front();
                            int x=curr.first;
                            int y=curr.second;
                            que.pop();
                    for(auto &dir:directions){
                        int ni=x+dir[0];
                        int nj=y+dir[1];
                        if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==1){
                            size++;
                            grid[ni][nj]=0;
                             que.push({ni,nj});
                         }
                      }
                   }
                }
                maxx = max(size,maxx);
             }
        }
        return maxx;
    }
};