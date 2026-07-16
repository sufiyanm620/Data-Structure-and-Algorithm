class Solution {
public:
    typedef pair<int,int> p;
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        queue<p> que;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                que.push({i,0});
                grid[i][0]=0;
            }
            if(grid[i][n-1]==1){
                que.push({i,n-1});
                grid[i][n-1]=0;
            }
            
        }
        for(int j=1;j<n-1;j++){
            if(grid[0][j]==1){
                que.push({0,j});
                grid[0][j]=0;
            }
            if(grid[m-1][j]==1){
                que.push({m-1,j});
                grid[m-1][j]=0;
            }
        }
        while(!que.empty()){
            p curr=que.front();
            int x = curr.first;
            int y = curr.second;
            que.pop();
            for(auto &dir:directions){
                int ni = x+dir[0];
                int nj = y+dir[1];
                if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]==1){
                    que.push({ni,nj});
                    grid[ni][nj]=0;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;

    }
};