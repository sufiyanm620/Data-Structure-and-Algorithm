class Solution {
public:
    int countDays(int days, vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector<int> &a,vector<int> &b){
                return a[0]<b[0];
        });
        int ans=0;
        int f=nums[0][1];
        int n=nums.size();
        ans+=nums[0][0]-1;
        for(int i=1;i<n;i++){
           int l=nums[i][0];
           if(l>f)
            ans+=l-f-1;
            f=max(f,nums[i][1]);
        }
        ans+=days-f;
        return ans;
    }
};