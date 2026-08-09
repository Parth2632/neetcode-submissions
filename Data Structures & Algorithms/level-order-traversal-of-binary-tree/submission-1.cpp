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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int level = q.size();
            vector<int>l;
            while(level--){
                auto top = q.front();
                q.pop();
                l.push_back(top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};
