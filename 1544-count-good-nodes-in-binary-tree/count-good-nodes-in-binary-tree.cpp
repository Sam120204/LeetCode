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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int max_so_far = root->val;
        int goodNode = 0;
        if_max(root, max_so_far, goodNode);
        
        return goodNode;
    }

    void if_max(TreeNode* root, int max_so_far, int& goodNode) {
        if (!root) return;
        bool if_good = true;
        
        if (root->val >= max_so_far) { goodNode++; }

        if_max(root->left, max(max_so_far, root->val), goodNode);
        if_max(root->right, max(max_so_far, root->val), goodNode);
    }   
};