class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
      
        for(int i=0;i<n;i++){
            if(s[i]!=')')
              st.push(s[i]);
            else{
                string ans = "";
                while(st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                for(char c : ans){
                    st.push(c);
                }
            }
            
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};