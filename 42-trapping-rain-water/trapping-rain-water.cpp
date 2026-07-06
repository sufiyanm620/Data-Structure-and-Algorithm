class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxl = INT_MIN;
        int maxr = INT_MIN;
        for(int i=0;i<n;i++){
            maxl = max(maxl,height[i]);
            maxr = max(maxr,height[n-1-i]);
            left[i]=maxl;
            right[n-1-i]=maxr;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(height[i]-min(left[i],right[i]));
        }
        return abs(ans);
    }
};