class Solution {
public:
    int n;
    bool isPossible(vector<int>& nums, int m,int mid){
        int count=1;
        int l=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-l>=mid){
                count++;
                l=nums[i];
            }
        }
        return count>=m;

    }
    int maxDistance(vector<int>& nums, int m) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int ans=-1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(nums,m,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};