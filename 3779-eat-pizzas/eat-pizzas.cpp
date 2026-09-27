class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans=0;
        priority_queue<int> pq;
        for(int x:pizzas) pq.push(x);
        int n=pizzas.size();
        int k=n/4;
        int m=(k+1)/2;
        int s=k/2;
        while(m--){
            ans+=pq.top();
            pq.pop();
        }
        while(s--){
            pq.pop();
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};