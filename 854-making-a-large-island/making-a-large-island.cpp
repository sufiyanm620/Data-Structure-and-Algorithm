class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int c0=0;
        int c1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) c0++;
                else c1++;
            }
        }
        if(c0==n*n) return 1;
        if(c1==n*n) return n*n;
        vector<vector<int>> dir{{-1,0},{0,-1},{0,1},{1,0}};
        queue<pair<int,int>> que;
        unordered_map<int,int> mp;
        int u=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1) continue;
                int size=1;
                if(grid[i][j]==1){
                    que.push({i,j});
                    grid[i][j]=u;
                    // size++;
                }
                while(!que.empty()){
                    auto [x,y]=que.front();
                    que.pop();
                    for(auto &d:dir){
                        int ni=x+d[0];
                        int nj=y+d[1];
                        if(ni<n&&nj<n&&ni>=0&&nj>=0&&grid[ni][nj]==1){
                            grid[ni][nj]=u;
                            size++;
                            que.push({ni,nj});
                        }
                    }
                }
                 mp[u]=size;
                u++;
               
            }
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               unordered_set<int> st;
               int ans=1;
               for(auto &d:dir){
                   int ni=i+d[0];
                   int nj=j+d[1];
                    if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]!=0)
                        st.insert(grid[ni][nj]);
}

                  for(int id:st)
                    ans+=mp[id];

maxx=max(maxx,ans);
            }
        }
        return maxx;
    }
};