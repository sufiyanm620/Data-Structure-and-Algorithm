class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp,freq;
        for(char c:s1) mp[c]++;
        int k=s1.size();
        int n=s2.size();
        int count=0;
        if(k>n) return false;
        for(int i=0;i<k;i++){
              if(mp.find(s2[i])!=mp.end()&&freq[s2[i]]<mp[s2[i]]) count++;
                freq[s2[i]]++;
        }
        if(count==k) return true;
        for(int i=k;i<n;i++){
        
            if(mp.find(s2[i])!=mp.end()&&freq[s2[i]]<mp[s2[i]]) count++;
                freq[s2[i]]++;
             freq[s2[i-k]]--;
            if(mp.find(s2[i-k])!=mp.end()&&freq[s2[i-k]]<mp[s2[i-k]]) count--;
           
            if(count==k) return true;
        }
        return false;
    }
};