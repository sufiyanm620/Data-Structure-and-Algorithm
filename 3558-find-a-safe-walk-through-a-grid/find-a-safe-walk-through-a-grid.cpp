class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0]=grid[0][0];
        dq.push_back({0,0});
        while(!dq.empty()){
            auto [i,j]=dq.front();
            dq.pop_front();
            for(auto &[dx,dy]:dir){
                int new_i = i+dx;
                int new_j = j+dy;
                if(new_i<0||new_j<0||new_i>=m||new_j>=n) continue;
                int newCost = dist[i][j]+grid[new_i][new_j];
                if(newCost<dist[new_i][new_j]){
                    dist[new_i][new_j]=newCost;
                    if(grid[new_i][new_j]==0)
                       dq.push_front({new_i,new_j});
                    else
                       dq.push_back({new_i,new_j});
                }
            }
        }
        return dist[m-1][n-1]<health;
    }
};