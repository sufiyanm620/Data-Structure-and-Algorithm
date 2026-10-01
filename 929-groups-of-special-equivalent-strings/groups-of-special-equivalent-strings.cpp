class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> mp;
        for(string s:words){
            int k=s.size();
            for(int i=0;i<k;i+=2){
                for(int j=i+2;j<k;j+=2){
                    if(s[j]<s[i])
                     swap(s[j],s[i]);
                }
            }
             for(int i=1;i<k;i+=2){
                for(int j=i+2;j<k;j+=2){
                    if(s[j]<s[i])
                     swap(s[j],s[i]);
                }
            }
            mp[s]++;
        }
        return mp.size();
        
        
    }
};