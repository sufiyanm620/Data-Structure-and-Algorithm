class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            sum=sum+('a'-s[i]+26)*(i+1);
        }
        return sum;
    }
};