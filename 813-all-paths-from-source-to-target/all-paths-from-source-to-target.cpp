class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> que;
        que.push({0});
        while(!que.empty()){
            int sz=que.size();
            while(sz--){
                auto res=que.front();
                que.pop();
                int curr=res.back();
                if(curr==graph.size()-1){
                    ans.push_back(res);
                    continue;
                }
                for(auto &v:graph[curr]){
                     vector<int> temp=res;
                     temp.push_back(v);
                     que.push(temp);
                }
            }    
        }
        return ans;
    }
};