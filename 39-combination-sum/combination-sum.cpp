class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    int n;
    void solve(vector<int>& nums, int tar,int i){
        if(i>=n)
           return ;
        if(tar==0){
            ans.push_back(res);

            return ;
        }   
        if(nums[i]<=tar){
           res.push_back(nums[i]);
           solve(nums,tar-nums[i],i);
           res.pop_back();
        }
        solve(nums,tar,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        solve(nums,target,0);
        return ans;
    }
};