class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        
        if (abs(leftHeight - rightHeight) > 1) return -1; // Current node is not balanced
        
        return max(leftHeight, rightHeight) + 1; // Return height of the tree
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
