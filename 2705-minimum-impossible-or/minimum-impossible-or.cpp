class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int ans=1;
        set<int> st;
        for(int x:nums) st.insert(x);
        while(st.count(ans))
          ans<<=1;
        return ans;
    }
};