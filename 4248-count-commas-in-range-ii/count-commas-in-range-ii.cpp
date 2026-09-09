class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        int comma = 1;
        long long start = 1000;
        while(n>=start){
            long long end = start*1000-1;
            long long upper = min(n,end);
            long long cnt = upper-start+1;
            ans += cnt*comma;
            start*=1000;
            comma++;
        }
        return ans;
    }
};