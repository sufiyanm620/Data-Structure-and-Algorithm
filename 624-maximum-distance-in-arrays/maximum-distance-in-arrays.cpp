class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int m=arr.size();
       priority_queue<pair<int,int>> pq1;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        vector<int> minnn;
        int n=arr[0].size();
        for(int i=0;i<m;i++){
              int minn=INT_MAX;
              int maxx=INT_MIN;
              int n=arr[i].size();
            for(int j=0;j<n;j++){
                maxx=max(maxx,arr[i][j]);
                minn=min(minn,arr[i][j]);
            }
            pq1.push({maxx,i});
            pq2.push({minn,i});
        }
        auto [m1,i]=pq1.top();
        auto [m2,j]=pq2.top();
        if(i!=j) return abs(m1-m2);
        pq1.pop();
        pq2.pop();
        auto [m3,x]=pq1.top();
        auto  [m4,y]=pq2.top();
        return max(abs(m1-m4),abs(m2-m3));

    }
};