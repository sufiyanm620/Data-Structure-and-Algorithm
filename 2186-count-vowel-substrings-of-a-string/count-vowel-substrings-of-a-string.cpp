class Solution {
public:
    int countVowelSubstrings(string s) {
        int n=s.size();
        int ans=0;
        
        for(int k=0;k<=n-5;k++){
         bool a=false;
        bool e=false;
        bool i=false;
        bool o=false;
        bool u=false;
            for(int j=k;j<n;j++){
             if(s[j]=='a') a=true;
             else if(s[j]=='e') e=true;
             else if(s[j]=='i') i=true;
             else if(s[j]=='o') o=true;
             else if(s[j]=='u') u=true;
             else break;
             if(a&&e&&o&&i&&u) ans++;
            }
            
        }
        return ans;

    }
};