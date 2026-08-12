class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int two=1;
        set<int> st;
        for(int x:nums) st.insert(x);
        while(st.count(two))
          two*=2;
        return two;
    }
};