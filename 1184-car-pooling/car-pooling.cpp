class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001,0);
        for(auto &trip:trips){
            int total = trip[0];
            int start = trip[1];
            int end = trip[2];
            diff[start]+=total;
            diff[end]-=total;
        }
        int curr=0;
        for(int x : diff){
            curr+=x;
            if(curr>capacity) return false;
        }
        return true;
    }
};