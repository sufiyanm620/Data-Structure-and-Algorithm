class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> res;
        vector<vector<int>> fck;
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
            if(i%3==1&&nums[i]-nums[i-1]>k) return fck;
            else if(i%3==2&&(nums[i]-nums[i-1]>k||nums[i]-nums[i-2]>k)) return fck;
            if(i%3==2){
                ans.push_back(res);
                res.clear();
            }
        }
        return ans;
    }
};