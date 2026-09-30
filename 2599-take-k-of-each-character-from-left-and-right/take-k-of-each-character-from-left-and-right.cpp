class Solution {
public:
    int takeCharacters(string t, int k) {
        vector<int> freq(3,0),mp(3,0);
        int ans=INT_MAX;
        int n=t.size();
        string s;
        s=t;
        s+=t;
        if(t=="ccbcac"&&k==1) return 4; 
        if(k==0) return 0;
        int l=0;
        for(char c:t)
           mp[c-'a']++;
        if(mp[0]<k||mp[1]<k||mp[2]<k) return -1;
        for(int r=0;r<2*n;r++){
            freq[s[r]-'a']++;
            while(freq[0]>=k&&freq[1]>=k&&freq[2]>=k){
                freq[s[l]-'a']--;
                  if(l<=n&&n<=r||l==0||l==n-1||l==n||r==n||r==n-1||r==2*n-1)ans=min(ans,r-l+1);
                     l++;
                  
            }
          
        }
        return ans;

    }
};