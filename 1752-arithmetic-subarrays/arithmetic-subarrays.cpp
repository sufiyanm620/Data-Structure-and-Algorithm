class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();
        vector<bool> ans(m,true);
        for(int i=0;i<m;i++){
            int s=l[i];
            int e=r[i];
            vector<int> temp;
            for(int j=s;j<=e;j++)
             temp.push_back(nums[j]);
            sort(temp.begin(),temp.end());
            bool flag=true;
            int diff=0;
            if(temp.size()>1)
                 diff=temp[1]-temp[0];
            for(int k=2;k<temp.size();k++){
                if(temp[k]-temp[k-1]!=diff){
                    flag=false;
                    break;
                }
            }
            if(!flag) ans[i]=false;
        }
        return ans;

    }
};