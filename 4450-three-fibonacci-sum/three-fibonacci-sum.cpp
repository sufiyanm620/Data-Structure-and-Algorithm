class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0;
        int b=1;
        long long c=0;
        long long MOD=1e9+7;
        for(int i=2;i<=n&&c<n;i++){
             c=a+b;
             if(1LL*(c+a+b)%MOD==(1LL*n)%MOD) return true;
             a=b;
             b=c;
        }
        return false;
    }
};