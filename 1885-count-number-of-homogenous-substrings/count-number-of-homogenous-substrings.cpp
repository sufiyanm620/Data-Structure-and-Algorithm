class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        int ans=0;
        int l=0;
        char c=s[0];
        int mod=1e9+7;
        for(int r=0;r<n;r++){
            if(s[r]==c){
                ans=(ans+r-l+1)%mod;
            }else{
                l=r;
                c=s[r];
                ans++;
            }
        }
        return ans%mod;
    }
};