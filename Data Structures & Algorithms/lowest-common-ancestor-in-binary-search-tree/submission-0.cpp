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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
        while(curr != nullptr){
            //Case 1, both nodes are in left subtree
            if(p->val < curr->val && q->val < curr->val){
                curr = curr->left;
            }else if(p->val > curr->val && q->val > curr->val){  //Case 2, both nodes are in right subtree
                curr = curr->right;
            }else{
                return curr;
            }
        }
        return nullptr;
    }
};

