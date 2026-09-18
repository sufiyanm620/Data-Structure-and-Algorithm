/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef pair<int,int> p;
    int ans=0;
    p solve(TreeNode* root){
        if(!root) return {0,0};
        p left=solve(root->left);
        p right=solve(root->right);
        int sum=left.first+right.first+root->val;
        int total=left.second+right.second+1;
        int ave=sum/total;
       if(ave==root->val) ans++;
       return {sum,total};
      
    }
    int averageOfSubtree(TreeNode* root) {
         solve(root);
         return ans;
    }
};