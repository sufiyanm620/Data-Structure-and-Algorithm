class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy=0;
        int yx=0;
        int x=0;
        int y=0;
        for(char c:s1){
            if(c=='x')x++;
            else y++;
        }
        for(char c:s2){
            if(c=='x') x++;
            else y++;
        }
        if(x%2==1&&y%2==1) return -1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x'&&s2[i]=='y') xy++;
            if(s1[i]=='y'&&s2[i]=='x') yx++; 
        }
        return (xy+1)/2+(yx+1)/2;
    }
};