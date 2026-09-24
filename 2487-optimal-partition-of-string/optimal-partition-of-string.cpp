class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        map<char,int> mp;
        int count=0;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])==0){
                mp[s[i]]++;
            }else{
                count++;
                mp.clear();
                mp[s[i]]++;
            }
        }
        return count+1;
    }
};