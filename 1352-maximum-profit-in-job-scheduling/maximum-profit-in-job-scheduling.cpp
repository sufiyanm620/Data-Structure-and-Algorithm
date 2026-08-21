class Solution {
public:
    int n;
    int getNext(vector<vector<int>> &arr,int l,int r,int target){
        int ans=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=target){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>> &arr,int i,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int next=getNext(arr,i+1,n-1,arr[i][1]);
        int pick = arr[i][2]+solve(arr,next,dp); 
        int skip=solve(arr,i+1,dp);
        return dp[i]=max(pick,skip);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pt) {
         n=st.size();
        vector<vector<int>> arr(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            arr[i][0]=st[i];
            arr[i][1]=et[i];
            arr[i][2]=pt[i];
        }
        sort(arr.begin(),arr.end());
        vector<int> dp(n,-1);
        return solve(arr,0,dp);

    }
};