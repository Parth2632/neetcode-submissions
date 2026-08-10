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
    int index = 0;
    unordered_map<int,int>m;
    TreeNode* build(vector<int>&preorder, int left, int right){
        if(left>right){
             return NULL;
        }
        int root = preorder[index];
        int idx = m[root];
        index++;
        TreeNode* node = new TreeNode(root);
        node->left = build(preorder,left,idx-1);
        node->right = build(preorder,idx+1,right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return build(preorder,0,inorder.size()-1);
    }
};
