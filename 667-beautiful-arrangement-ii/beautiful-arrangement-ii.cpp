class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        bool flag=true;
        int j=1;
        int f=n;
        while(k>1){
            if(flag){
                ans.push_back(j);
                flag=false;
                j++;
            }
            else{
                ans.push_back(f);
                flag=true;
                f--;
            }
            k--;
        }
        if(flag){
            while(j<=f){
                ans.push_back(j);
                j++;
            }
        }
        else{
            while(f>=j){
                ans.push_back(f);
                f--;
            }
        }
        return ans;
    }
};