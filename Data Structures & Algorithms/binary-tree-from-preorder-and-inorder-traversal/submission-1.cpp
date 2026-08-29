#include <vector>
#include <unordered_map>

// this guy was super tricky, do not count this as a pass, this is just to get through to the next


class Solution {
    std::unordered_map<int, int> inMap;
    int preIndex = 0;

    TreeNode* build(const std::vector<int>& preorder, int inLeft, int inRight) {
        if (inLeft > inRight) {
            return nullptr;
        }

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inMap[rootVal];

        // Left subtree must be constructed before Right subtree
        // to match preorder iteration order
        root->left = build(preorder, inLeft, mid - 1);
        root->right = build(preorder, mid + 1, inRight);

        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        preIndex = 0;
        inMap.clear();

        int n = static_cast<int>(inorder.size());
        for (int i = 0; i < n; ++i) {
            inMap[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1);
    }
};
