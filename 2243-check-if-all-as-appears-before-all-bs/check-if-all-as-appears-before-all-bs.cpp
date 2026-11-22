class Solution {
public:
    bool checkString(string s) {
          bool foundb=false;
          for(char c:s){
            if(c=='b')
              foundb=true;
            if(c=='a'&&foundb)
              return false;
          }   
          return true;
    }
};