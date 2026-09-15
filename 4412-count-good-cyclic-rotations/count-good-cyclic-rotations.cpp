class Solution {
public:
    typedef long long ll;
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int h=n/2;
        ll suml=0;
        ll sumr=0;
        for(int i=0;i<h;i++) suml+=nums[i];
        for(int i=h;i<n;i++) sumr+=nums[i];
        int ans=0;
        // if(suml>sumr) ans++;
        for(int i=0;i<n;i++){
            suml=suml+nums[(h+i)%n];
            suml=suml-nums[i%n];
            sumr=sumr+nums[i%n];
            sumr=sumr-nums[(h+i)%n];
            if(suml>sumr) ans++;
        }
        return ans;
    }
};