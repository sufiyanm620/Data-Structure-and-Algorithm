class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for(int i=0;i<bookings.size();i++){
            int start = bookings[i][0];
            int end = bookings[i][1];
            int m = bookings[i][2];
            for(int j=start-1;j<=end-1;j++){
                res[j]+=m;
            }
        }
        return res;
    }
};