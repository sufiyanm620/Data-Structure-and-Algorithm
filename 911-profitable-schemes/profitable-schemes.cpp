class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m;
    int MOD=1e9+7;
    int solve(int i,int n,int mp,vector<int>& group,vector<int>& profit){
        if(i==m) return mp<=0;
        if(dp[i][n][mp]!=-1) return dp[i][n][mp];
        int skip=solve(i+1,n,mp,group,profit);
        int take=0;
        if(group[i]<=n){
            take=solve(i+1,n-group[i],max(0,mp-profit[i]),group,profit);
        }
        return dp[i][n][mp]=(take+skip)%MOD;
    }
    int profitableSchemes(int n,int mp, vector<int>& group, vector<int>& profit) {
        m=group.size();
        dp.assign(m,vector<vector<int>>(n+1,vector<int>(mp+1,-1)));
        return solve(0,n,mp,group,profit);
    }
};