class Solution {
public:
    vector<vector<int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
    typedef pair<int,int> p;
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1')
                    mat[i][j]=1;
            }
        }
        int count=0;
        queue<p> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                    mat[i][j]=0;
                    que.push({i,j});
                    while(!que.empty()){
                    p curr = que.front();
                    int x = curr.first;
                    int y = curr.second;
                    que.pop();
                    for(auto &dir:directions){
                        int ni=x+dir[0];
                        int nj=y+dir[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&mat[ni][nj]==1){
                                que.push({ni,nj});
                                mat[ni][nj]=0;
                            }
                        }
                    }
                }
            } 
        }
        return count;

    }
};