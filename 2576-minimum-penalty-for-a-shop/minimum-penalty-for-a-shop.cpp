class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int> res(n+1);
        res[0]=0;
        int sum=0;
        int i=1;
        for(char c : s){
            if(c=='Y') sum++;
            else sum--;
            res[i]=sum;
            i++;
        }
        int maxx = *max_element(res.begin(),res.end());
        for(int i=0;i<=n;i++){
            if(res[i]==maxx){
                return i;
        }
        }
        return -1;
    }
};