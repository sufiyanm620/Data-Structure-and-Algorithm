class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            int l=i;
            int r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(mat[i][mid]==t) return true;
                else if(mat[i][mid]<t) l=mid+1;
                else r=mid-1;
            }
        }
        for(int i=0;i<n;i++){
             int l=i;
             int r=m-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(mat[mid][i]==t) return true;
                else if(mat[mid][i]<t) l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};