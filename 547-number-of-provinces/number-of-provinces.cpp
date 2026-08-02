class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp) return;
        if(rank[xp]>rank[yp]) parent[yp]=xp;
        else if(rank[yp]>rank[xp]) parent[xp]=yp;
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        int count=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]&&find(i)!=find(j)){
                    Union(i,j);
                    count--;
                }
            }
        }
        return count;

    }
};