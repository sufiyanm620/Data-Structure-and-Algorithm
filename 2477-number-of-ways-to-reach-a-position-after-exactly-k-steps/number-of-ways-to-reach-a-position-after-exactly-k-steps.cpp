class Solution {
public:
    vector<vector<int>> dp;
    const int MOD = 1e9+7;
    int solve(int i,int k){
        if(i>k) return 0;
         if(k==0) return i==0;
         if(dp[i][k]!=-1) return dp[i][k];
         return dp[i][k]=(solve(abs(i-1),k-1)+solve(i+1,k-1))%MOD;
    }
    int numberOfWays(int s, int e, int k) {
        dp.resize(k+1,vector<int>(k+1,-1));
        int d=abs(s-e);
        return solve(d,k);
    }
};