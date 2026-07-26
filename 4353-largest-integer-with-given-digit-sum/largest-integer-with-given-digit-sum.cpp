class Solution {
public:
    int largestInteger(int n, int s) {
        int num=0;
        if(n*9<s) return -1;
        while(s){
            if(s>=9){
                num=num*10+9;
                s-=9;
                n--;
            }
            else{
                num=num*10+s;
                s=0;
                n--;
            } 
        }
        while(n--){
            num*=10;
        }
        return num;
        
    }
};