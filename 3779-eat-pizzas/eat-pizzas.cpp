class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans=0;
        int n=pizzas.size();
        sort(pizzas.begin(),pizzas.end());
        int k=n/4;
        int m=(k+1)/2;
        int s=k/2;
        int j=n-1;
        for(int i=0;i<m;i++){
            ans+=pizzas[j];
            j--;
        }
        int f=j-1;
        for(int i=0;i<s;i++){
            ans+=pizzas[f];
            f-=2;
        }
        return ans;
    }
};