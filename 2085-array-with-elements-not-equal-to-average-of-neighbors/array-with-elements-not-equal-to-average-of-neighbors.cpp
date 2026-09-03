class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=(n+1)/2;
        int i=0;
        vector<int> ans;
        while(i<(n+1)/2||j<n){
            if(i<(n+1)/2){
            ans.push_back(nums[i]);
            i++;
            }
            if(j<n){
            ans.push_back(nums[j]);
            j++;
            }
        }
        return ans;

    }
};