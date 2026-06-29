class Solution {
public:
    long long minimumSteps(string s) {
        long long count=0;
        int n = s.size();
        int i=0;
        int j=0;
        while(j<n&&i<n){
            if(s[i]=='0'){
                i++;
                j++;
            }
            if(s[i]=='1'){
                while(s[j]!='0'){
                    if(j==n-1)
                    return count;
                    j++;
                }
                swap(s[i],s[j]);
                count+=j-i;
                i++;
            }
        }
        return count;
    }
};