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
    void dfs(TreeNode* node, int& k, int& seen, int& res) {
        if (!node) return;
        dfs(node->left, k, seen, res);
        seen++;
        if (seen == k) {
            res = node->val;
            return;
        }
        dfs(node->right, k, seen, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int seen = 0, res = 0;
        dfs(root, k, seen, res);
        return res;
    }
};