class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int totalM=0;
        int totalP=0;
        int totalG=0;
        int lastM=0;
        int lastP=0;
        int lastG=0;
        for(int i=0;i<n;i++){
             for( int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M'){
                 lastM=i;
                 totalM++;
                }
                else if(garbage[i][j]=='P'){
                  lastP=i;
                  totalP++;
                }
                else if(garbage[i][j]=='G'){
                    lastG=i;
                    totalG++;
                }
             }
        }
        int a=totalM;
        int b=totalP;
        int c=totalG;
        int ans=a+b+c;
        a=0;
        b=0;
        c=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M')
                 a=max(a,i);
                else if(garbage[i][j]=='P')
                 b=max(b,i);
                else if(garbage[i][j]=='G')
                 c=max(c,i);
            }
        }
        for(int i=0;i<travel.size();i++){
            if(i<a) ans+=travel[i];
            if(i<b) ans+=travel[i];
            if(i<c) ans+=travel[i];
        }
        return ans;
    }
};