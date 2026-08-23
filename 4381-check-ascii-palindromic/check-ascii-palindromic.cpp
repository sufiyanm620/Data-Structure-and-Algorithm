class Solution {
public:
    bool isPalindromic(string s) {
        string b="";
        for(char c:s){
            int x=(int)c;
            int i=0;
            while(i<8){
                b+=to_string(x%2);
                x/=2;
                i++;
            }
        }
        int l=0;
        int r=b.size()-1;
        while(l<r){
            if(b[l]!=b[r])
                 return false;
            l++;
            r--;
        }
        return true;
    }
};