class Solution {
public:
    typedef long long ll;
    int n;
    bool isPossible(vector<int>& nums, int cars,ll mid){
        ll count=0;
        for(int i=0;i<n;i++){
            count+=sqrt(mid/nums[i]);
        }
        return count>=cars;
    }
    long long repairCars(vector<int>& nums, int cars) {
         n=nums.size();
        ll l=1;
        ll r=LLONG_MAX;
        ll ans=r;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(isPossible(nums,cars,mid)){
                ans=mid;
                r=mid-1;
            } 
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};