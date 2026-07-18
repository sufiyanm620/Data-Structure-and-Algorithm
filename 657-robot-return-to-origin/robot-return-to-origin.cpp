class Solution {
public:
    bool judgeCircle(string moves) {
        int ud=0;
        int lr=0;
        for(char c : moves){
            if(c=='U') ud++;
            else if(c=='D') ud--;
            else if(c=='L') lr++;
            else lr--; 
        }
        return ud==0&&lr==0;
    }
};