class Solution {
public:
    string minRemoveToMakeValid(string s) {
       int open = 0;
       int close = 0;
       stack<char> st;
       int n = s.size();
       for(char c : s){
        if(c==')'&&close>=open) continue;
            st.push(c);
            if(c=='(') open++;
            if(c==')') close++;
        
    }
       string ans="";
       while(!st.empty()){
        ans+=st.top();
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       if(open>close){
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=='('){
                 ans.erase(i,1);
                open--;
                if(open==close) break;
            }
        }
       }
       return ans;
    }
};