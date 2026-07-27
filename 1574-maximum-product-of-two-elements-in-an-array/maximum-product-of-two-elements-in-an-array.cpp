class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1=0;
        int m2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>m1){
                m2=m1;
                m1=nums[i];
               
            }
            else if(nums[i]>m2){
                m2=nums[i];
            }
        }
        return (m1-1)*(m2-1);
    }
};