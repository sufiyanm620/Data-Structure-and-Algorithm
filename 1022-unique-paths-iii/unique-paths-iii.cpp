class Solution {
public:
    int m;
    int n;
    int solve(int i,int j,vector<vector<int>> &grid,int r){
        if(grid[i][j]==2) return r==0;
     
        grid[i][j]=-1;
        int right=0,left=0,up=0,down=0;
        if(i+1<m&&grid[i+1][j]!=-1) right=solve(i+1,j,grid,r-1);
        if(i-1>=0&&grid[i-1][j]!=-1) left=solve(i-1,j,grid,r-1);
        if(j+1<n&&grid[i][j+1]!=-1) down=solve(i,j+1,grid,r-1);
        if(j-1>=0&&grid[i][j-1]!=-1) up=solve(i,j-1,grid,r-1);
        grid[i][j]=0;
        return right+left+up+down;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int x=-1;
        int y=-1;
        int nonobs=0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
            if(grid[i][j]!=-1) nonobs++;
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        return solve(x,y,grid,nonobs-1);
    }
};