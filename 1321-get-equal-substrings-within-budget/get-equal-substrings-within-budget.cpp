class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            res[i]=abs(s[i]-t[i]);
        }
        int ans=0;
        int l=0;
        int sum=0;
        for(int r=0;r<n;r++){
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