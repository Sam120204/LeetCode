class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getDepth(root, diameter);
        return diameter;
    }
    
    int getDepth(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int leftDepth = getDepth(node->left, diameter);
        int rightDepth = getDepth(node->right, diameter);
        
        // Update the diameter at this node
        diameter = max(diameter, leftDepth + rightDepth);
        
        // Return the height of the tree rooted at this node
        return 1 + max(leftDepth, rightDepth);
    }
};
