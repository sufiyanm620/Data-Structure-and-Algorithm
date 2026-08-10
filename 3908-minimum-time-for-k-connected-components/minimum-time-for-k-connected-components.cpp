class Solution {
public:
    vector<int> rank,parent;
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
    bool isPossible(int mid,vector<vector<int>> &edges,int k,int n){
        rank.resize(n,0);
        parent.resize(n);
        int count=n;
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(wt>mid&&find(u)!=find(v)){
                 Union(u,v);
                 count--;
            }
        }
        return count>=k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int r=1e9+7;
        int l=0;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(mid,edges,k,n)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
       return ans;

    }
};