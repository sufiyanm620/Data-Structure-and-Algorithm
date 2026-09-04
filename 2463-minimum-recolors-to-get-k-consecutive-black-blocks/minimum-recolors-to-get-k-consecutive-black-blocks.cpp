class Solution {
public:
    int minimumRecolors(string s, int k) {
        int b=0;
        int n=s.size();
        for(int i=0;i<k;i++){
            if(s[i]=='B') b++;
        }
        int count=k-b;
        if(count==0) return 0;
        int ans=count;
        for(int i=k;i<n;i++){
               if(s[i-k]=='W'&&s[i]=='B') count--;
               else if(s[i]=='W'&&s[i-k]=='B') count++;
               ans=min(ans,count);
        }
        return ans;

    }
};