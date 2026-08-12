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
    int helper(TreeNode *root, int &maxi){
        if(root==NULL){
            return 0;
        }
        int leftsum = max(0,helper(root->left,maxi));
        int rightsum = max(0,helper(root->right,maxi));
        maxi = max(root->val+leftsum+rightsum,maxi);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};
