class Solution {
public:
    bool isPalindrome(string s,int i,int j,vector<vector<int>> &dp){
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return false;
        return dp[i][j]=isPalindrome(s,i+1,j-1,dp);
    }
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j,dp)){
                  count++;
                }
            }
        }
        return count;
    }
};