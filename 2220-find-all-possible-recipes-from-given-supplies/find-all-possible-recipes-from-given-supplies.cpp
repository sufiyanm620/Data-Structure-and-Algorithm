class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> ans;
        vector<bool> res(n,false);
        unordered_map<string,int> freq;
        for(string &s : supplies) freq[s]++;
        int m=n;
        while(m--){
        for(int i=0;i<ingredients.size();i++){
                bool check = true;
                for(string &t:ingredients[i]){
                    if(freq.find(t)==freq.end()){
                        check = false;
                         break;
                     }
                }
                if(check){
                    res[i]=true;
                    freq[recipes[i]]++;
                }
        } 
    }  
        for(int i=0;i<n;i++){
            if(res[i]) ans.push_back(recipes[i]);
        }

        return ans;
    }
};