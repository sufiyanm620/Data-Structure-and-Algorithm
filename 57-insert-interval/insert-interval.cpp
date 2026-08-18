class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& nw) {
        int x=nw[0];
        int y=nw[1];
        int n=nums.size();
        int i=0;
        if(n==0) return {{x,y}};
        vector<vector<int>> ans;
        while(i<n&&nums[i][1]<x){
             ans.push_back(nums[i]);
             i++;
        }
         while(i<n&&nums[i][0]<=y){
            x=min(nums[i][0],x);
            y=max(nums[i][1],y);
            i++;
         }
         ans.push_back({x,y});
            while(i<n){
                ans.push_back(nums[i]);
                i++;
            }
       
        return ans;
    }
};