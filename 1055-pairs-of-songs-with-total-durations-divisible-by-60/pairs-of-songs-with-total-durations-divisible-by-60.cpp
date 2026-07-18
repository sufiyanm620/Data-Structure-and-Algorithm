class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        unordered_map<int,int> freq;
        for(int t:time){
              int rem = t%60;
              int need = (60-rem)%60;
                count+=freq[need];
            
            freq[rem]++;
        }
        return count;
    }
};