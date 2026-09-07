class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    int solve(int i,int j,string& s,string& t){
        if(j==n) return 1;
        if(i>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick=0;
        if(s[i]==t[j]){
            pick=solve(i+1,j+1,s,t);
        }
        int skip=solve(i+1,j,s,t);
        return dp[i][j]=pick+skip;
    }
    int numDistinct(string s, string t) {
        m=s.size();
        n=t.size();
        dp.assign(1001,vector<int>(1001,-1));
        return solve(0,0,s,t);
    }
};