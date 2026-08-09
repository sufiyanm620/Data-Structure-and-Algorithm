class Solution {
public:
    // vector<long long> res(26,0);
    //     long long sum=0;
    //      char c=s[0];
    //      bool flag=true;
    //     for(int i=0;i<s.size();i++){
    //         long long m=s[i]-'a';
    //         res[m]+=cost[i];
    //         sum+=cost[i];
    //         if(s[i]!=c) flag = false; 
    //     }
    //     if(flag) return 0;
    //     int m=*max_element(res.begin(),res.end());
    //     return sum-m;
    long long minCost(string s, vector<int>& cost) {
        int n=s.size();
        unordered_map<char,long long> mp;
        long long sum=0;
        for(int i=0;i<n;i++){
            mp[s[i]]+=cost[i];
            sum+=cost[i];
        }
        long long ans=sum;
        for(auto &it:mp){
            ans=min(ans,sum-it.second);
        }
        return ans;
        
    }
};