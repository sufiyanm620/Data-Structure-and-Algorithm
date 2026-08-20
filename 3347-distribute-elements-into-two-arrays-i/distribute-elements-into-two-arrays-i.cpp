class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2;
         int n=nums.size();
        vector<int> ans(n);
       
        int l1=nums[0];
        arr1.push_back(l1);
        int l2=nums[1];
        arr2.push_back(l2);
        for(int i=2;i<n;i++){
            if(l1>l2){
                arr1.push_back(nums[i]);
                l1=nums[i];
            }
            else{
                arr2.push_back(nums[i]);
                l2=nums[i];
            }
        }
       arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};