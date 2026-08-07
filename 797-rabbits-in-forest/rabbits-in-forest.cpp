class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int x:answers) mp[x]++;
        int ans=0;
        for(auto &it:mp){
            int k=it.first+1;
            int m=it.second;
            int g=(m+k-1)/k;
            ans+=g*k;  
        }
        return ans;
    }
};