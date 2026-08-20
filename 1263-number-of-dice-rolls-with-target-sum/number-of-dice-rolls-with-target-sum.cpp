class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD=1e9+7;
    int solve(int i,int x,int t,int n,int k){
        if(i==n) return t==0;
        if(x>k||x>t) return 0;
        if(dp[i][x][t]!=-1) return dp[i][x][t];
        int pick=solve(i+1,1,t-x,n,k);
        int skip=solve(i,x+1,t,n,k);
        return dp[i][x][t]=(pick+skip)%MOD;
    }
    int numRollsToTarget(int n, int k, int t) {
        dp.assign(n+1,vector<vector<int>>(k+2,vector<int>(t+1,-1)));
        return solve(0,1,t,n,k);  
    }
};