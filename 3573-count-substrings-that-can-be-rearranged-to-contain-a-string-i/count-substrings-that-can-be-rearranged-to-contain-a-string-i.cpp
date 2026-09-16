class Solution {
public:
    long long validSubstringCount(string s, string t) {
         int m=s.size();
         int n=t.size();
         unordered_map<char,int> mp,freq;
         for(char c:t) mp[c]++;
         long long ans=0;
         int l=0;
         int count=0;
         for(int i=0;i<m;i++){
            char x=s[i];
            freq[x]++;
            if(mp.find(x)!=mp.end()&&freq[x]<=mp[x]) count++;
            while(count==n){
                ans+=m-i;
                freq[s[l]]--;
                if(freq[s[l]]==0)
                 freq.erase(s[l]);
                if(mp.find(s[l])!=mp.end()&&freq[s[l]]<mp[s[l]]) count--;
                l++;
            }
         }
         return ans;
    }
};