class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
          int n=intervals.size();
          vector<vector<int>> temp;
          for(int i=0;i<n;i++){
            temp.push_back({intervals[i][0],intervals[i][1],i});
          }
          sort(temp.begin(),temp.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
          });
          for(int i=0;i<n;i++){
            int k=-1;
            int l=i;
            int r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(temp[mid][0]>=temp[i][1]){
                    k=temp[mid][2];
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            temp[i].push_back(k);
          }
          vector<int> ans(n);
          sort(temp.begin(),temp.end(),[](vector<int> &a,vector<int> &b){
            return a[2]<b[2];
          });
          for(int i=0;i<n;i++){
            ans[i]=temp[i][3];
          }
          return ans;
    }
};