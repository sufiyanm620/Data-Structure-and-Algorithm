class Solution {
public:
    int minMoves(vector<int>& nums) {
       int m = *min_element(nums.begin(),nums.end());
       int sum=0;
       for(int x : nums) sum+=x-m;
       return sum;
    }
};