class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxx = INT_MIN;
        vector<int> arr(n);
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            maxx = max(nums[i],maxx);
            arr[i] = maxx;
        }
        for(int i=0;i<n;i++){
            prefix[i]=__gcd(nums[i],arr[i]);
            
        }
        sort(prefix.begin(),prefix.end());
        long long ans = 0;
        int a =0;
        int b=n-1;
        while(a<b){
            ans += __gcd(prefix[a],prefix[b]);
            a++;
            b--;
        }
        
        return ans;
    }
};