class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n=nums.size();
        int l=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]<p) l++;
            if(nums[i]==p) c++;
        }
        int k=0;
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<p){
                res[k]=nums[i];
                k++;
            }
        }
        for(int i=l;i<l+c;i++) res[i]=p;
        int r=l+c;
        for(int i=0;i<n;i++){
            if(nums[i]>p){
                res[r]=nums[i];
                r++;
            }
        }
        return res;
    }
};