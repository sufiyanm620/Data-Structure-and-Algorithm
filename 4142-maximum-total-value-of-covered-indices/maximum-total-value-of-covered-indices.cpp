class Solution {
public:
    int n;
    long long ans=0;
    vector<vector<long long>> dp;
    long long solve(int i,bool flag,vector<int> &nums,string &s){
        if(i>=n) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        long long ans=0;
        if(s[i]=='0'){
            return dp[i][flag]=solve(i+1,false,nums,s);
        }
        long long stay=nums[i]+solve(i+1,false,nums,s);
        long long move=LLONG_MIN;
        if(i>0&&(s[i-1]=='0'||flag)){
            move=nums[i-1]+solve(i+1,true,nums,s);
        }

        return dp[i][flag]=max(stay,move);
    }
    long long maxTotal(vector<int>& nums, string s) {
        n=s.size();
        dp.resize(n,vector<long long>(2,-1));
       
        return solve(0,false,nums,s);
    }
};