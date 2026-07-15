class Solution {
public:
    int m;
    int n;
    int solve(string &word1, string &word2,int i,int j,vector<vector<int>> &dp){
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(word1,word2,i+1,j+1,dp);
        }else{
            return dp[i][j]=min({1+solve(word1,word2,i+1,j,dp),1+solve(word1,word2,i,j+1,dp),1+solve(word1,word2,i+1,j+1,dp)});
        }
    }
    int minDistance(string word1, string word2) {
          m = word1.size();
          n = word2.size();
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};