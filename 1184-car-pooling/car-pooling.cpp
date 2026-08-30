class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto &it:trips){
                int l=it[1];
                int r=it[2];
                int pass=it[0];
                mp[l]+=pass;
                mp[r]-=pass;
        }
        int prev=-1;
        int total=0;
        for(auto [x,change]:mp){
            if(prev!=-1&&total!=0){
                if(total>capacity) return 0;
            }
            total+=change;
            prev=x;
        }
        return true;
    }
};