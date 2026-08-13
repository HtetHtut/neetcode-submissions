class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }

        TreeNode* temp_node = root->left;
        root->left = root->right;
        root->right = temp_node;
 
        if(root->right!=nullptr){
            invertTree(root->right);
        }
        if(root->left!=nullptr){
            invertTree(root->left);
        }
        return root;
    }
};
