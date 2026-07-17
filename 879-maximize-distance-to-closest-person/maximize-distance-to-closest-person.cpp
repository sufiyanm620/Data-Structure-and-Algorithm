class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxgap=0;
        int maxx = 0;
        int n=seats.size();
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                maxgap=max(maxgap,maxx);
                maxx=0;
            }else{
                maxx++;
            }
        }
        int left=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1) break;
            else left++;
        }
        int right=0;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1) break;
            else right++;
        }
        return max({(maxgap+1)/2,left,right});
    }
};