class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int n=s1.size();
        bool ans1=true;
        bool ans2=true;
        for(int i=0;i<n;i++){
            if(s1[i]>s2[i]) ans1 = false;
        }
        for(int i=0;i<n;i++){
            if(s1[i]<s2[i]) ans2 = false;
        }
        return ans1||ans2;
    }
};