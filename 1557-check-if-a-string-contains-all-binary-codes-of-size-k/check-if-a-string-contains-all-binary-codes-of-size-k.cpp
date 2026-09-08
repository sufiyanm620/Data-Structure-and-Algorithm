class Solution {
public:
    bool hasAllCodes(string s, int k) {
         int n=s.size();
         map<string,int> mp;
         string res="";
         if(n<k) return false;
         for(int i=0;i<k;i++){
            res+=s[i];
         }
         mp[res]++;
         for(int i=k;i<n;i++){
                res.erase(0,1);
                res+=s[i];
                mp[res]++;
         }
         return mp.size()==1<<k;
    }
};
    // map<string,int> mp;
    //     int n=s.size();
    //     int count=0;
    //     for(int i=0;i<n-k;i++){
    //         string res="";
    //         for(int j=i;j<i+k;j++){
    //             res+=s[j];
    //         }
    //         if(mp.find(res)==mp.end()) count++;
    //         mp[res]++;
            
    //     }
    //     return count==pow(2,k);