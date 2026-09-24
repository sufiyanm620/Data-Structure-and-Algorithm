class Solution {
public:
    bool isPossible(string s,string p,int mid,vector<int>& nums){
        int m=p.size();
        int l=0;
        int n=s.size();
        int i=0;
        vector<bool> removed(n,false);
        for(int i=0;i<mid;i++){
            removed[nums[i]]=true;
        }
        while(i<n&&l<m){
            if(removed[i]){
                i++;
                continue;
            }
            if(s[i]==p[l]){
                l++;
            }
            i++;
        }
        return l==m;
    }
    int maximumRemovals(string s, string p, vector<int>& nums) {
        int l=0;
        int r=nums.size();
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(s,p,mid,nums)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};