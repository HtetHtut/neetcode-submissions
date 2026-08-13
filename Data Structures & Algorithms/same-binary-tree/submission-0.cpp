class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr && q!=nullptr) return false;
        if(p!=nullptr && q==nullptr) return false;

        bool is_same = true;
        if(p->left!=nullptr && q->left!=nullptr){
            is_same &= isSameTree(p->left, q->left);
        }
        if(p->right!=nullptr && q->right!=nullptr){
            is_same &= isSameTree(p->right, q->right);
        }
        if(p->left!=nullptr && q->left==nullptr){
            is_same &= false;
        }
        if(p->left==nullptr && q->left!=nullptr){
            is_same &= false;
        }
        if(p->right!=nullptr && q->right==nullptr){
            is_same &= false;
        }
        if(p->right==nullptr && q->right!=nullptr){
            is_same &= false;
        }
        if(p->val!=q->val){
            is_same &= false;
        }
        return is_same;
    }
};
