class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        int m=a.size();
        int n=b.size();
        int x=n/m;
        for(int i=0;i<x;i++) s+=a;
        if(s.find(b)!=string::npos) return x;
        s+=a;
        if(s.find(b)!=string::npos) return x+1;
        s+=a;
       if(s.find(b)!=string::npos) return x+2;
        
        return -1;
    }
};