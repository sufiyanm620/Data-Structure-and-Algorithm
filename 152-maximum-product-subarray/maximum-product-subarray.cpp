class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suff=1;
        int pref=1;
        int maxx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(suff==0) suff=1;
            if(pref==0) pref=1;
            suff*=nums[i];
            pref*=nums[n-1-i];
            maxx=max(maxx,max(suff,pref));  
        }
        return maxx;
    }
};