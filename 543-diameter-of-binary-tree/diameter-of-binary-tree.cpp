class Solution {
    int getdiameter(TreeNode* root, int& diameter) {
        if (!root) return -1;  // Height of an empty subtree is -1
        
        int left = getdiameter(root->left, diameter);
        int right = getdiameter(root->right, diameter);
        
        // Update the diameter at this node
        diameter = max(diameter, left + right + 2);  // +2 to count edges through the root
        
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
