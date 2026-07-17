class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> res(n,false);
        queue<pair<int,int>> que;
        que.push({start,arr[start]});
        res[start]=true;
        int x = 0;
        while(!que.empty()){
            int k=que.size();
            while(k--){
             auto[idx,val]=que.front();
            if(val==0) return true;
            que.pop();
            if(idx+val<n&&!res[idx+val]){
                que.push({idx+val,arr[idx+val]});
                res[idx+val]=true;
            }if(idx-val>=0&&!res[idx-val]){
                que.push({idx-val,arr[idx-val]});
                res[idx-val]=true;
            }
        }
        x++;
        if(x==n) break;
     }
     return false;
    }
};