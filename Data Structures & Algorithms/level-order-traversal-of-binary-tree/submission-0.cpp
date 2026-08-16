#include <vector>

class Solution {
private:
    void vectorBuilder(TreeNode* node, std::vector<std::vector<int>>& vec, int depth){
        if(node==nullptr) return;

        std::vector<int> current_vector{};
        if(depth>=vec.size()){
            vec.push_back(current_vector);
        }
        vec[depth].push_back(node->val);
        vectorBuilder(node->left, vec, depth+1);
        vectorBuilder(node->right, vec, depth+1);
    }
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root){
        std::vector<std::vector<int>> val_vector{};
        vectorBuilder(root, val_vector, 0);
        return val_vector;
    }
};
