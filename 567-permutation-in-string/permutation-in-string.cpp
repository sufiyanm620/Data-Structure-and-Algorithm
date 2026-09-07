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
              freq[s2[i]]++;
        }
        if(mp==freq) return true;
        for(int i=k;i<n;i++){
             freq[s2[i]]++;
             freq[s2[i-k]]--;
             if(freq[s2[i-k]]==0)
               freq.erase(s2[i-k]);
            if(freq==mp) return true;
        }
        return false;
    }
};