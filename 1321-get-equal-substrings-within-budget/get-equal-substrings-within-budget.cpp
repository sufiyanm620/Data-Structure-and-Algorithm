class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> res(s.size());
        for(int i=0;i<s.size();i++){
            res[i]=abs(s[i]-t[i]);
        }
        int l=0;
        int sum=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            sum+=res[r];
            while(sum>maxCost){
                sum-=res[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;

    }
};