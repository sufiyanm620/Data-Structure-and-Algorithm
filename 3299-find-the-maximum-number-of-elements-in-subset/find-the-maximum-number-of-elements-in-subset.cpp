class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<ll,int> freq;
        set<ll> st;
         int count1=0;
        for(ll x : nums){
            if(x==1)count1++;
        freq[x]++;
        st.insert(x);
    }
       int maxCount=1;
      
       for(ll x : st){
        if(x==1)
        continue;
        if(freq[x]>=2){
            int count=2;
            long long m = 1LL*x*x;
            while(freq[m]>1){
                count+=2;
                m=1LL*m*m;
            }
            if(freq[m]==1){
                 maxCount=max(count+1,maxCount);
            }else{
                maxCount=max(count-1,maxCount);
            }
        }
       }
       return max(maxCount,(count1-1)/2*2+1);
        
    }
};