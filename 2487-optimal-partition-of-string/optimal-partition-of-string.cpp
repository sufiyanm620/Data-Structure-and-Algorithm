class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int count=0;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==0){
                freq[s[i]-'a']++;
            }else{
                count++;
                for(int i=0;i<26;i++) freq[i]=0;
                freq[s[i]-'a']++;
            }
        }
        return count+1;
    }
};