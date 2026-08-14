class Solution {
private:
    void serializeTree(TreeNode* node, std::string& out){
        if(!node){
            out.append(",#");
            return;
        }
        out += (",") + std::to_string(node->val);
        serializeTree(node->left, out);
        serializeTree(node->right, out);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::string root_string, sub_string;
        serializeTree(root, root_string);
        serializeTree(subRoot, sub_string);
        return root_string.find(sub_string) != std::string::npos;
    }
};
