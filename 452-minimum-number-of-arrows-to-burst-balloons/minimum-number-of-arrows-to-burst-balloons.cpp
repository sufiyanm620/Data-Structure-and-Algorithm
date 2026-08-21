class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int count=1;
        int l1=arr[0][0];
        int r1=arr[0][1];
        int l2;
        int r2;
        for(int i=1;i<n;i++){
            l2=arr[i][0];
            r2=arr[i][1];
            if(min(r2,r1)>=max(l2,l2)){        
                l1=(max(l1,l2));
                r1=(min(r1,r2));
            }else{
                count++;
                l1=l2;
                r1=r2;
            }
        }
        return count;

    }
};