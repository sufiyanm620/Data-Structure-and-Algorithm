class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,int> mp;
        int n=s.size();
        int count=0;
        for(int i=0;i<=n-k;i++){
            string res="";
            for(int j=i;j<i+k;j++){
                res+=s[j];
            }
            if(mp.find(res)==mp.end()) count++;
            mp[res]++;
            
        }
        return count==(1<<k);
    }
};
    