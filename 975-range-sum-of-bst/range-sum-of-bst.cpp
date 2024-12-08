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
    int getSum(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (low <= root->val and root->val <= high) {
            int left = getSum(root->left, low, high);
            int right = getSum(root->right, low, high);
            return left+right+root->val;
        } else if (root->val < low) {
            return getSum(root->right, low, high);
        } else {
            return getSum(root->left, low, high);
        }
        return -1;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return getSum(root, low, high);
    }
};