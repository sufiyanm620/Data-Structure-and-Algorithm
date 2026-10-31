class Solution {
public:
    int n;
    int isPossible(vector<int>& arr,int mid){
        int total=0;
        for(int x:arr)
            total+=min(mid,x);
        return total;
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        n=arr.size();
        int l=0;
        int r=*max_element(arr.begin(),arr.end());
        int ans=0;
        int sum=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=isPossible(arr,mid);
            if(sum>=target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int sum1=isPossible(arr,l);
        int sum2=isPossible(arr,r);
        return (abs(sum1-target)<abs(sum2-target))?l:r;
    }
};