class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(!q.empty()){
            int level = q.size();

            while(level--){
                TreeNode* top = q.front();
                q.pop();

                if(level == 0){
                    ans.push_back(top->val);
                }

                if(top->left){
                    q.push(top->left);
                }

                if(top->right){
                    q.push(top->right);
                }
            }
        }

        return ans;
    }
};
