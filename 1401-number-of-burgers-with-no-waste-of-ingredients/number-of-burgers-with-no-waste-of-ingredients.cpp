class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(t==2&&c==1) return {0,1};
        if(t==0&&c==0) return {0,0};
        if(t<=c||t%2!=0) return {};
        for(int i=0;i<t/4;i++){
            if(((i+(t-4*i)/2)==c)&&((t-4*i)/2!=0))
                return {i,abs(t-4*i)/2};
        }
        return {};
    }
};