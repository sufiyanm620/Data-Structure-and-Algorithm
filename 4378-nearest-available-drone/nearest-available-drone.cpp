class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int count=0;
        int m=target[0];
        int n=target[1];
        int ans=-1;
        int i=1;
        vector<int> res;
        for(auto &it:drones){
            int x=it[0];
            int y=it[1];
            int z=it[2];
            
            
            if(abs(x-m)+abs(y-n)<=z)
                res.push_back(abs(x-m)+abs(y-n));
            else 
                res.push_back(-1);
            
        }
        int g=res.size();
        int minn=INT_MAX;
        int f=-1;
        for(int i=g-1;i>=0;i--){
            if(res[i]<=minn&&res[i]!=-1){
                minn=res[i];
                f=i;
            }
        }
        return f;
    }
};