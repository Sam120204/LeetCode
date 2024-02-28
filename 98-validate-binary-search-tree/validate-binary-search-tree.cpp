class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Use long long type for the limits to handle edge cases with INT_MIN and INT_MAX
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long lower, long long upper) {
        if (!node) return true;
        int val = node->val;
        // Check if current node's value is within the valid range
        if ((long long)val <= lower || (long long)val >= upper) return false;
        // Recursively validate the left and right subtrees
        return validate(node->left, lower, val) && validate(node->right, val, upper);
    }
};
