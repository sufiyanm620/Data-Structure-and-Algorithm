class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int> mp;
        int i=0;
        for(char c:chars){
            mp[c]=vals[i];
            i++;
        }
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end())
              arr[i]=mp[s[i]];
            else
              arr[i]=s[i]-'a'+1;
        }
        int count=0;
        for(int i=0;i<n;i++){
            ans=max(ans,count);
            count+=arr[i];
            if(count<0)
             count=0;
        }
        return max(ans,count);
    }
};