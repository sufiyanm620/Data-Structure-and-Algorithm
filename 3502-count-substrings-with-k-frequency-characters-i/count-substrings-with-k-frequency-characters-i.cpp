class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        map<char,int> mp;
        int l=0;
        int ans=0;
        if(n<k) return 0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]==k){
                ans+=n-r;
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};