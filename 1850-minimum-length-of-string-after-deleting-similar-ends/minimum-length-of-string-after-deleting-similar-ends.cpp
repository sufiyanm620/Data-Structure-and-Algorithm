class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        int count=n;
        bool check =false;
        while(l<r){
            if(s[l]==s[r]){
                if(!check)count-=2;
                else count-=1;
                if(s[l+1]==s[r]){
                    check = true;
                    l++;
                }
                else if(s[r-1]==s[l]){
                    r--;
                    check = true;
                }
                else{
                    l++;
                    r--;
                    check = false;
                }
            }else break;
        }
        return count;
    }
};