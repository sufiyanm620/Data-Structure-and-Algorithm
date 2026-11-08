class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
         set<int> row;
         set<int> col;
         int m=grid.size();
         int n=grid[0].size();
         for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                    if(count==2){
                        row.insert(i);
                        break;
                    }
                }
            }
         }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==1){
                    count++;
                    if(count==2){
                        col.insert(i);
                        break;
                    }
                }
            }
         }
         int ans=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&(row.count(i)||col.count(j)))
                 ans++;
            }
         }
         return ans;
    }
};