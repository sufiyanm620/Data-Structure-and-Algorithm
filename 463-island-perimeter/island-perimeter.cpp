class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                if(i-1>=0&&grid[i-1][j]==1) mat[i-1][j]++;
                if(i+1<m&&grid[i+1][j]==1) mat[i+1][j]++;
                if(j-1>=0&&grid[i][j-1]==1) mat[i][j-1]++;
                if(j+1<n&&grid[i][j+1]==1) mat[i][j+1]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                   ans+=(4-mat[i][j]);
            }
        }
        return ans;
    }
};