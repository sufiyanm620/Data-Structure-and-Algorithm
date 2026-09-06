class Solution {
public:
    string minWindow(string s, string p) {
            int m=s.size();
            int n=p.size();
            map<char,int> mp;
            for(char c:p) mp[c]++;
            vector<int> freq(256,0);
            int l=0;
            int lm=0;
            int minn=INT_MAX;
            int count=0;
            for(int i=0;i<m;i++){
                freq[s[i]]++;
                if(mp.find(s[i])!=mp.end()&&freq[s[i]]<=mp[s[i]]) count++;
                while(count==n){
                    if(i-l+1<minn){
                        minn=i-l+1;
                        lm=l;
                    }
                    freq[s[l]]--;
                    if(mp.find(s[l])!=mp.end()&&mp[s[l]]>freq[s[l]]) count--;
                    l++;
                }
            }
            return minn==INT_MAX?"":s.substr(lm,minn);
    }
};