class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        maxGain(root, globalMax);
        return globalMax;
    }

private:
    int maxGain(TreeNode* node, int& globalMax) {
        if (!node) {
            return 0;
        }

        // Recursively compute the max gain from left and right subtrees.
        // If a subtree returns a negative sum, clamp to 0 (ignore the branch).
        int leftGain = std::max(0, maxGain(node->left, globalMax));
        int rightGain = std::max(0, maxGain(node->right, globalMax));

        // 1. Check path that peaks/turns around at the current node
        int currentPathSum = node->val + leftGain + rightGain;
        globalMax = std::max(globalMax, currentPathSum);

        // 2. Return the maximum single branch extendable to the parent
        return node->val + std::max(leftGain, rightGain);
    }
};

// The trick to this is to calculate each sub path and treat them as nodes on a single path
// this is a mix of dfs and dynamic programming
