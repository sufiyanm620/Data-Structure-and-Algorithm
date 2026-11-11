class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c : num){
            while(k>0 && !st.empty() && st.top()>c){
                      st.pop();
                      k--;
            }
                    st.push(c);
                
        }
         while(k>0 && !st.empty()){
                      st.pop();
                      k--;
            }
       string s = "";
       while(!st.empty()){
         s += st.top();
         st.pop();
       }
       reverse(s.begin(),s.end());
       int i = 0;
       while(i<s.size() && s[i] == '0') i++;
       s = s.substr(i);
       return s.empty()? "0" : s;
    }
};