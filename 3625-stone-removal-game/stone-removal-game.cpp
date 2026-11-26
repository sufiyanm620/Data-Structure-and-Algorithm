class Solution {
public:
    bool canAliceWin(int n) {
        int i=10;
        bool ans = false;
        while(n>=i){
            n-=i;
            i--;
            ans = !ans;
        }
        return ans;
    }
};