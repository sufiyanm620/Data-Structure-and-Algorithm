class Solution {
public:
    string evaluate(string s,vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto &it:knowledge){
            mp[it[0]]=it[1];
        }
        int j=0;
        
       string ans="";
       for(int i=0;i<s.size();i++){
        bool flag=true;
        bool flag2=true;
        if(s[i]=='('){
            string t="";
             j=i+1;
             flag=false;
             flag2=false;
            while(s[j]!=')'){
                t+=s[j];
                j++;
            }
            i=j+1;
            if(mp.find(t)!=mp.end()){
                ans+=mp[t];
            }else{
                ans+='?';
               
            }
        }
        else ans+=s[i];
        if(!flag) i--;
        
       }
       return ans;
    }
};