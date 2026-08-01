class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return ;
        if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(auto &it:edges){
            if(find(it[0])==find(it[1])) return {it};
            Union(it[0],it[1]);
        }
        return {-1,-1};
    }
};