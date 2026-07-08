class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,int> p;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mint=0;
        int countf=0;
       
        queue<p> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) countf++;
                if(grid[i][j]==2) que.push({i,j});
            }
        }
        while(!que.empty()){
            int f = que.size();
             bool change=false;
            for(int k=0;k<f;k++){
            p front=que.front();
            int i=front.first;
            int j=front.second;
            que.pop();
            for(auto & dir : directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&grid[new_i][new_j]==1){
                  grid[new_i][new_j]=2;
                  que.push({new_i,new_j}); 
                  change=true; 
                }
            }
        }
         if(change)mint++;
    }
        int countS=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) countS++;
            }
        }
        return (countf==countS)?mint:-1;

    }
};