class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            nums[i]=sum;
        }
        int minn = *min_element(nums.begin(),nums.end());
        return (minn<0)?abs(minn)+1:1;
    }
};