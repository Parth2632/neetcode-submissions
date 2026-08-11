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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root==NULL){
            return "";
        }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node==NULL){
                s+= "#,";
            }
            else{
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        string temp = "";
        vector<string>v;
        for(auto c: data){
            if(c==','){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += c;
            }
        }
        queue<TreeNode*>q;
        TreeNode * root = new TreeNode(stoi(v[0]));
        q.push(root);
        int i = 1;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(v[i]!="#"){
                top->left = new TreeNode(stoi(v[i]));
                q.push(top->left);
            }
            i++;
            if(v[i]!="#"){
                top->right = new TreeNode(stoi(v[i]));
                q.push(top->right);
            }
            i++;
        }
        return root;
    }
};
