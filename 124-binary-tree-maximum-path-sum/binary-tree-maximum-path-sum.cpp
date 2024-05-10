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
public:
    int dfs(TreeNode* root, vector<int>& res) {
        if (!root) return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int lmax = max(left, 0);
        int rmax = max(right, 0);
        res[0] = max(res[0], root->val+lmax+rmax);
        return root->val + max(lmax, rmax);
    }
    int maxPathSum(TreeNode* root) {
        vector<int> res = {root->val};
        dfs(root, res);
        return res[0];
    }
};