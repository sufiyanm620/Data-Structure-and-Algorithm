class Solution {
public:
    int maxProduct(int n) {
      vector<int> nums;
      while(n){
        nums.push_back(n%10);
        n/=10;
      }
      sort(nums.begin(),nums.end());
      int m = nums.size();
      return nums[m-1]*nums[m-2];
          
        
    }
};