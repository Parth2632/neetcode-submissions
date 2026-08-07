class Solution {
public:

    int ans = 0;

    int height(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left,right);
    }


    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        ans = max(ans, leftheight + rightheight);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return ans;
    }
};