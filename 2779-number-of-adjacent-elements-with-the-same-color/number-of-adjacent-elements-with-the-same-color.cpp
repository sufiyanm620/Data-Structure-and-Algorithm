class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n,0);
        int count=0;
        int k=0;
        bool flag=false;
        vector<int> ans(queries.size(),0);
        for(auto &it:queries){
            int i=it[0];
            int c=it[1];
            if(i>0&&color[i]!=0&&color[i]==color[i-1]){
                count--;
            }
            if(i<n-1&&color[i]!=0&&color[i]==color[i+1]){
                count--;
            }
            color[i]=c;
            if(i>0&&color[i]!=0&&color[i]==color[i-1]) count++;
            if(i<n-1&&color[i]!=0&&color[i]==color[i+1]) count++;
            ans[k]=count;
            k++;
        }
        return ans;
    }
};