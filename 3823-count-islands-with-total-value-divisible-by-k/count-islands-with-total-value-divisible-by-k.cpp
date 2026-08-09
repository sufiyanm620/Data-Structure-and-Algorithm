class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
        int ans=0;
        long long sum;
        bool flag;
        queue<pair<int,int>> que; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flag=false;
                if(grid[i][j]!=0){
                    sum=0;
                    flag=true;
                    sum+=grid[i][j];
                    que.push({i,j});
                    grid[i][j]=0;
                    while(!que.empty()){
                        auto [x,y]=que.front();
                        que.pop();
                        for(auto &d:dir){
                            int ni=x+d[0];
                            int nj=y+d[1];
                            if(ni>=0&&nj>=0&&ni<m&&nj<n&&grid[ni][nj]!=0){
                                sum+=grid[ni][nj];
                                que.push({ni,nj});
                                grid[ni][nj]=0;
                            }
                        }
                    }
                }
                    if(flag&&sum%k==0)
                        ans++;
                }
            }
        return ans;
    }
};