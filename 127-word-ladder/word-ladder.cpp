class Solution {
public:
    int ladderLength(string b, string e, vector<string>& word) {
        unordered_set<string> st(word.begin(),word.end());
        if(!st.count(e)) return 0;
        queue<string> que;
        que.push(b);
        int steps=1;
        st.erase(b);
        while(!que.empty()){
            int sz=que.size();
            while(sz--){
                auto curr=que.front();
                que.pop();
                if(curr==e) return steps;
                for(int i=0;i<curr.size();i++){
                    char o=curr[i];
                    for(char c='a';c<='z';c++){
                        curr[i]=c;
                        if(st.count(curr)){
                            que.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=o;
                }
            }
            steps++;
        }
        return 0;
    }
};