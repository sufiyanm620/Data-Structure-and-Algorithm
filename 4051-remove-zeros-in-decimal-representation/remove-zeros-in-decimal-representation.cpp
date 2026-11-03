class Solution {
public:
    long long removeZeros(long long n) {
        long long ans=0;
        long long m=n;
        while(m){
            if(m%10!=0) ans=ans*10+m%10;
            m/=10;
        }
         m=ans;
        ans=0;
        while(m){
            ans=ans*10+m%10;
            m/=10;
        }
        return ans;
    }
};