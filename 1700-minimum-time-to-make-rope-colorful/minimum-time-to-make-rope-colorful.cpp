class Solution {
public:
    int minCost(string s, vector<int>& nums) {
        int ans=0;
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i+1;
            int maxx=nums[i];
            int total=nums[i];
            bool flag=false;
            while(j<n&&s[i]==s[j]){
                total+=nums[j];
                 maxx=max(maxx,nums[j]);
                j++;
                flag=true;
               
            }
            i=j;
            if(flag)ans=ans+(total-maxx);
        }
        return ans;
      
    }
};
 