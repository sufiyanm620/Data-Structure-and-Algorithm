class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    long long solve(string s,int k){
        unordered_map<char,int> mp;
        long long ans=0;
        int n=s.size();
        int l=0;
        int con=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i]))
              mp[s[i]]++;
            else 
              con++;
            while(mp.size()==5&&con>=k){
                 if(isVowel(s[l])){
                   mp[s[l]]--;
                  if(mp[s[l]]==0)
                   mp.erase(s[l]);
                 }else con--;
                l++;
            }
            ans+=l;
        }
        return ans;
    }
    long long countOfSubstrings(string s, int k) {
        return solve(s,k)-solve(s,k+1);
    }
};