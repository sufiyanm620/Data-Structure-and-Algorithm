class Solution {
public:
    bool canConstruct(string s, int k) {
         vector<int> freq(26,0);
         if(k>s.size()) return false;
         for(char c:s){
            freq[c-'a']++;
         }
         int oddCount=0;
         for(int x:freq){
            if(x%2==1) oddCount++;
         }
         return oddCount<=k;
    }
};