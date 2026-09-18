class Solution {
public:
    vector<long long> dp;
    int m;
    long long solve(int i,vector<vector<int>>& rides){
        if(i>=m) return 0;
        if(dp[i]!=-1) return dp[i];
        int next=lower_bound(rides.begin()+1+i,rides.end(),vector<int>{
            rides[i][1],0,0})-rides.begin();
        long long pick=rides[i][1]-rides[i][0]+rides[i][2]+solve(next,rides);
        long long skip=solve(i+1,rides);
        return dp[i]=max(pick,skip);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides){
        m=rides.size();
        sort(rides.begin(),rides.end());
        dp.resize(m,-1);
        return solve(0,rides);

    }
};