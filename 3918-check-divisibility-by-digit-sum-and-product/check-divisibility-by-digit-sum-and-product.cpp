class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,mul=1;
        int m=n;
        while(n){
            sum+=n%10;
            mul*=n%10;
            n/=10;
        }
        return m%(sum+mul)==0;        
    }
};