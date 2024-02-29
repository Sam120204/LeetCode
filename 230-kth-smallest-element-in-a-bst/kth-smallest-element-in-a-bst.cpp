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
    int kthSmallest(TreeNode* root, int k) {
        int seen = 0, res = 0;
        dfs(root, seen, k, res);
        return res;
    }

    void dfs(TreeNode* root, int& seen, int k, int& res) {
        if (!root || seen >= k) return;
        dfs(root->left, seen, k, res);
        seen++;
        if (seen == k) {
            res = root->val; 
            return;
        } 
        dfs(root->right, seen, k, res);

    }
};