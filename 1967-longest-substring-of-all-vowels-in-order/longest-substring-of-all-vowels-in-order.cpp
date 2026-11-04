class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int n=s.size();
        int ans=0;
        int count=0;
        if(s.empty()||n<5) return 0;
        char last=s[0];
        int j=0;
        while(j<n&&s[j]!='a'){
            j++;
        }
        if(j==n) return 0;
        last=s[j];
        bool yes=false;
        count=1;
        for(int i=j+1;i<n;i++){
              if(s[i]==last) count++;
              else if((last=='a'&&s[i]=='e')||(last=='e'&&s[i]=='i')||(last=='i'&&s[i]=='o')||(last=='o'&&s[i]=='u')){
              count++;
              last=s[i];
              if(s[i]=='u') yes=true;
              }
              else{
                if(yes) ans=max(count,ans);
                yes=false;
                count=0;
                bool flag=false;
                while(i<n&&s[i]!='a'){
                    i++;
                }
                if(i==n) flag=true;
                count=1;
                last='a';
              }
        }
        if(yes) ans=max(ans,count);
        return ans;
    }
};