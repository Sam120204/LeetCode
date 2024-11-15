/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isLeftandRight(TreeNode* left, TreeNode* right) {
        if (left == nullptr and right == nullptr) return true;
        if (left == nullptr or right == nullptr) return false;
        return (left->val == right->val and isLeftandRight(left->left, right->right) and isLeftandRight(left->right, right->left));

    }
public:
    bool isSymmetric(TreeNode* root) {
        return isLeftandRight(root->left, root->right);
        
    }
};