class Solution {
public:
    int minFlips(string s) {
       char ch='0';
       int count=0;
       for(char c:s){
            if(c!=ch){
                count++;
                ch=(ch=='0')?'1':'0';
            }
       }
       return count;
    }
};