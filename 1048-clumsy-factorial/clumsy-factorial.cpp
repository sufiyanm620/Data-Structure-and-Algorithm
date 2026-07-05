class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        int k=0;
        st.push(n);
        for(int i=n-1;i>=1;i--){
            if(k%4==0){
                if(!st.empty()){
                    int m = st.top();
                    st.pop();
                    st.push(m*i);
                }
                else st.push(i);
            }
            else if(k%4==1){
                if(!st.empty()){
                    int j = st.top();
                    st.pop();
                    st.push(j/i);
                }else st.push(i);
            }
            else if(k%4==2){
                st.push(i);
            }else{
                st.push(-i);
            }
            k++;
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};