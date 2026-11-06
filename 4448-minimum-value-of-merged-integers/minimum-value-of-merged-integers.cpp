class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n/2);
        int j=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i+=2){
            string st=to_string(nums[i+1]);
            int  temp=nums[i+1]+nums[i]*pow(10,st.size());
            res[j]=temp;
            ans=min(ans,res[j]);
            j++;

        }
        return ans;
    }
};