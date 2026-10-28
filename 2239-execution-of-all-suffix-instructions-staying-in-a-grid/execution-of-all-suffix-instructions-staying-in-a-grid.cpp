class Solution {
public:
    int m;
    pair<int,int> dir(char c){
        if(c=='U') return {-1,0};
        else if(c=='D') return {1,0};
        else if(c=='L') return {0,-1};
        else  return {0,1};
    }
    int solve(int i,int j,int l,string s,int n){
         int count=0;
         for(int k=l;k<m;k++){
            auto curr=dir(s[k]);
            int f=curr.first;
            int g=curr.second;
            if(i+f>=0&&j+g>=0&&i+f<n&&j+g<n){
                count++;
                i+=f;
                j+=g;
            }
            else break;
         }
         return count;
    }
    vector<int> executeInstructions(int n, vector<int>& start, string s) {
       int x=start[0];
       int y=start[1];
        m=s.size();
       vector<int> ans(m,0);
       for(int i=0;i<m;i++){
           int k=solve(x,y,i,s,n);
           ans[i]=k;
       }
       return ans;

    }
};
//   if(i>=n||j>=n||i<0||j<0||l>=m) return 0;
//         auto curr=dir(s[l]);
//         return 1+solve(i+curr.first,j+curr.second,l+1,s,n);