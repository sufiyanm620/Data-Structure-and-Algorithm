class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& worker) {
        int m=diff.size();
        vector<vector<int>> temp;
        for(int i=0;i<m;i++){
            temp.push_back({diff[i],pro[i]});
        }
        sort(temp.begin(),temp.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });
        int last=temp[0][1];
        for(int i=1;i<m;i++){
            if(temp[i][1]<last)
              temp[i][1]=last;
            else 
              last=temp[i][1];
        }
        int ans=0;
        sort(worker.begin(),worker.end());
        int j=0;
        int n=worker.size();
        for(int i=0;i<n;i++){
             while(j<m&&temp[j][0]<=worker[i]){
                j++;
                if(j==m) break;
             }
            
            if(j>0) ans+=temp[j-1][1];
        }
          return ans;  
    }
  
};