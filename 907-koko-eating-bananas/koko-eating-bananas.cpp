class Solution {
public:
    bool isPossible(vector<int>& piles,long long mid,int h){
        long long res=0;
        for(int i=0;i<piles.size();i++){
            res+=(piles[i]+mid-1)/mid;
        }
        return res<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long sum=0;
        for(int x:piles) sum+=x;
        int l=1;
        long long r=sum;
        int ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(isPossible(piles,mid,h)){
                 ans=mid;
                 r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};