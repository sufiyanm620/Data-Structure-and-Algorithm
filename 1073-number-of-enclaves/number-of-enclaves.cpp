class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==1){
                    int count=1;
                    bool flag=false;
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    grid[i][j]=0;
                    while(!que.empty()){
                        auto [x,y]=que.front();
                        que.pop();
                       
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni<0||nj<0||ni>=m||nj>=n) continue;
                            if(grid[ni][nj]==1){
                                if(ni==0||nj==0||ni==m-1||nj==n-1)
                                flag=true;
                                que.push({ni,nj});
                                grid[ni][nj]=0;
                                count++;
                    
                                }
                            }    
                    }
                   
                   if(!flag)ans+=count;      
                }
                
            }
        }
        return ans;
    }
};