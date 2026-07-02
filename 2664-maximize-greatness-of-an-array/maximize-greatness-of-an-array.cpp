class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
         while(r<n&&l<n){
                if(nums[l]<nums[r]){
                count++;
                r++;
                l++;
            }else{
                r++;
            }
        }
        return count;
    }
};