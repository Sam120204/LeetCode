class Solution {
    int getdiameter(TreeNode* root, int& diameter) {
        if (!root) return 0;  // Base case: height of empty subtree is 0
        
        int left = getdiameter(root->left, diameter);
        int right = getdiameter(root->right, diameter);
        
        // Update the diameter at this node
        diameter = max(diameter, left + right);
        
        // Return the height of the subtree rooted at this node
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getdiameter(root, diameter);
        return diameter;
    }
};
