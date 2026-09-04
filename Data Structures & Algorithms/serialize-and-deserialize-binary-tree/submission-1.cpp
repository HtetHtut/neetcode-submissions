class Codec {
public:

    // Encodes a tree to a single std::string.
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serializeHelper(root, out);
        return out.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream in(data);

        return deserializeHelper(in);
    }
private:
    void serializeHelper(TreeNode* node, std::ostream& out) {
        if(!node) {
            out << "# ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(std::stringstream& in) {
        
        std::string value;
        if(!(in>>value) || value == "#") {
            return nullptr;
        }
        
        auto* node = new TreeNode(std::stoi(value));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};
