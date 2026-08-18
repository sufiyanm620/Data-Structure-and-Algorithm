class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
      
        int n=mat[0].size();
        int j=n-1;
          int i=0;
          int m=mat.size();
        while(i<m&&j>=0){
            if(mat[i][j]==t) return true;
            else if(mat[i][j]>t) j--;
            else i++;
        }
        return false;
    }
};