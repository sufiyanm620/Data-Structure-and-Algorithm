class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,int> P;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<P> que;
        int maxx = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=1;
                    grid[i][j]=0;
                    que.push({i,j});
                    while(!que.empty()){
                       P curr=que.front();
                       que.pop();
                       int x=curr.first;
                       int y=curr.second;
                    
                        for(auto &dir:directions){
                          int new_i=x+dir[0];
                          int new_j=y+dir[1];
                          if(new_i>=0&&new_j>=0&&new_i<m&&new_j<n&&grid[new_i][new_j]==1){
                            size++;
                            grid[new_i][new_j]=0;
                            que.push({new_i,new_j});
                         }
                    }
                }
                    maxx = max(maxx,size);
                }
            }
        }
        return maxx;
    }
};