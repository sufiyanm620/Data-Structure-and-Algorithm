class Solution {
public:
    int movesToMakeZigzag(vector<int>& arr) {
        int n=arr.size();
        int ans1=0;
        for(int i=1;i<n;i+=2){
            int l=0;
            int r=0;
            if(i-1>=0)
             l=arr[i]-arr[i-1]+1;
            if(i+1<n)
             r=arr[i]-arr[i+1]+1;
             ans1+=max(0,max(l,r));
        }
        int ans2=0;
         for(int i=0;i<n;i+=2){
            int l=0;
            int r=0;
            if(i-1>=0)
             l=arr[i]-arr[i-1]+1;
            if(i+1<n)
             r=arr[i]-arr[i+1]+1;
            ans2+=max(0,max(l,r));
         }
        return min(ans1,ans2);
    }
};