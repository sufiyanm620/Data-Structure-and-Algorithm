class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i==m||j==n){
              return -1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int val=nums1[i]*nums2[j];
        int take2=nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2);
        int skipi=solve(i,j+1,nums1,nums2);
        int skipj=solve(i+1,j,nums1,nums2);
        return dp[i][j]=max({take2,skipi,skipj,val});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(0,0,nums1,nums2);

    }
};