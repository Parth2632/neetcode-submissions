class Solution {
public:

    bool helper(TreeNode* root, long long minvalue, long long maxvalue){
        if(root == NULL){
            return true;
        }

        if(root->val <= minvalue || root->val >= maxvalue){
            return false;
        }

        return helper(root->left, minvalue, root->val) &&
               helper(root->right, root->val, maxvalue);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
