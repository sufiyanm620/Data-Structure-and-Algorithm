class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n>m) return {};
        
        map<char,int> mp,freq;
        for(char c:t) mp[c]++;
        vector<int> ans;
        int count=0;
        for(int i=0;i<n;i++){
                 if(mp.find(s[i])!=mp.end()&&freq[s[i]]<mp[s[i]])
                  count++;
                  freq[s[i]]++;
                 
        }
        if(count==n)
          ans.push_back(0);
           
            for(int j=n;j<m;j++){
                if(mp.find(s[j])!=mp.end()&&freq[s[j]]<mp[s[j]])
                  count++;
                  freq[s[j]]++;
                  char c=s[j-n];
                  if(mp.find(c)!=mp.end()&&freq[c]<=mp[c]) count--;
                  freq[c]--;
                  if(freq[c]==0)
                    freq.erase(c);
            if(count==n) 
            ans.push_back(j-n+1);
        }
        return ans;
    }
};