class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,int> p;
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m = grid.size();
        int n = grid[0].size();
        int x = grid[sr][sc];
        queue<p> que;
        que.push({sr,sc});
        
        grid[sr][sc]=color;
        while(!que.empty()){
            int sz=que.size();
            for(int k=0;k<sz;k++){
                p front = que.front();
                que.pop();
                int i=front.first;
                int j=front.second;
                for(auto &dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&grid[new_i][new_j]==x&&x!=color){
                        grid[new_i][new_j]=color;
                        que.push({new_i,new_j});
                    }
                }
            }
        }
        return grid;
        
     }
};