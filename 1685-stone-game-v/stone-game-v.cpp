class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int l,int r,vector<int> &sum){
         if(l>=r) return 0;
         if(dp[l][r]!=-1) return dp[l][r];
         int score=0;
         for(int mid=l;mid<=r-1;mid++){
                int leftSum=sum[mid]-(l-1>=0?sum[l-1]:0);
                int rightSum=sum[r]-sum[mid];
                if(leftSum>rightSum){
                    score=max(score,rightSum+solve(mid+1,r,sum));
                }
                else if(rightSum>leftSum){
                    score=max(score,leftSum+solve(l,mid,sum));
                }
                else{
                    score=max({score,rightSum+solve(mid+1,r,sum),leftSum+solve(l,mid,sum)});
                }
         }
        return dp[l][r]=score;
    }
    int stoneGameV(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector<int>(n,-1));
         vector<int> sum(n,0);
         sum[0]=nums[0];
        for(int i=1;i<n;i++){
             sum[i]=sum[i-1]+nums[i];
        }
        return solve(0,n-1,sum);
    }
};