class Solution {
public:
    int n;
    int l=0;
    int r=1;
    vector<vector<int>> dp;
    bool solve(string &s,int i,int j){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return false;
        return dp[i][j]=solve(s,i+1,j-1);
    }
    string longestPalindrome(string s) {
        n=s.size();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)&&(j-i+1>r)){
                    l=i;
                    r=j-i+1;
                }
            }
        }
        return s.substr(l,r);

    }
};