class Solution {
public:
    int m;
    int n;
    bool isPossible(vector<int>& houses, vector<int>& heaters,int mid){
        int j=0;
        int count=0;
        int i=0;
        while(i<n){
            while(j<m&&abs(heaters[i]-houses[j])<=mid){
                j++;
                count++;
                if(count==m) return true;
            }
            i++;
        }
        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        m=houses.size();
        n=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l=0;
        int ans=-1;
        int r=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(houses,heaters,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};