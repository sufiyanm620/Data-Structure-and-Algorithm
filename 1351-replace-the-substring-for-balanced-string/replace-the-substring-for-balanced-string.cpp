class Solution {
public:
    int balancedString(string s) {
        vector<int> freqq(4,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='E') freqq[0]++;
            else if(s[i]=='R') freqq[1]++;
            else if(s[i]=='Q') freqq[2]++;
            else freqq[3]++;
        }
        int k=n/4;
        map<int,int> mp;
        int count =0;
        for(int i=0;i<4;i++){
            if(freqq[i]>k){
                mp[i]=freqq[i]-k;
                count+=freqq[i]-k;
            }
        }
        if(count==0) return 0;
        int ans=INT_MAX;
        vector<int> freq(4,0);
        int l=0;
        int curr=0;
        for(int i=0;i<n;i++){
            int j=0;
           if(s[i]=='E') j=0 ;
            else if(s[i]=='R') j=1;
            else if(s[i]=='Q') j=2;
            else j=3;
            freq[j]++;
            if(mp.find(j)!=mp.end()&&mp[j]>=freq[j]) curr++;
            while(curr==count){
                ans=min(ans,i-l+1);
                int left=0;
                  if(s[l]=='E') left=0 ;
                  else if(s[l]=='R') left=1;
                  else if(s[l]=='Q') left=2;
                   else left=3;
                if(mp.find(left)!=mp.end()&&freq[left]<=mp[left]) curr--;
                freq[left]--;
                l++;
            }
        }
        return ans;
    }
};