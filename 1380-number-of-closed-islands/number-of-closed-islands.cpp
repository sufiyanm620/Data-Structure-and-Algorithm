class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
       int count =0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                bool flag=true;
                if(i==0||j==0||i==m-1||j==n-1)
                   flag=false;
                grid[i][j]=1;
                queue<pair<int,int>> que;
                que.push({i,j});
                while(!que.empty()){
                    int sz=que.size();
                    while(sz--){
                        auto [r,c]=que.front();
                        que.pop();
                        for(auto &d:dir){
                            int nr=r+d[0];
                            int nc=c+d[1];
                            if(nr>=0&&nc>=0&&nr<m&&nc<n&&grid[nr][nc]!=1){
                                que.push({nr,nc});
                                grid[nr][nc]=1;
                                if(nr==0||nc==0||nr==m-1||nc==n-1) 
                                  flag=false;
                            }
                        }
                    }
                }
                  if(flag) count++;
            }
          
        }
       }   
       return count;
    }
};