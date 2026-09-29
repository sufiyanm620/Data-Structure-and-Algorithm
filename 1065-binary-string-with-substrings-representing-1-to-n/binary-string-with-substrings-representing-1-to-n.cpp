class Solution {
public:
    bool queryString(string s, int n) {
        int sz=s.size();
        for(int i=1;i<=n;i++){
            string t="";
            int x=i;
            while(x){
                 if(x%2==1) t+='1';
                 else t+='0';
                x/=2;
            }
            reverse(t.begin(),t.end());
            int k=t.size();
            bool flag=false;
            string p="";
            for(int i=0;i<k;i++){
                 p+=s[i];
            }
            if(p==t) continue;
            for(int i=k;i<sz;i++){
                p.erase(0,1);
                p+=s[i];
                if(p==t){
                    flag=true;
                    continue;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};