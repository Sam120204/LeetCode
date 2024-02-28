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
        vector<TreeNode*> path = {nullptr};
        int goodNode = 0;
        if_max(root, path, goodNode);
        
        return goodNode;
    }

    void if_max(TreeNode* root, vector<TreeNode*> path, int& goodNode) {
        if (!root) return;
        bool if_good = true;

        for (const auto& node:path) {
            if (node and node->val > root->val) {
                if_good = false;
                break;
            }
        }
        if (if_good) { goodNode++; }
        path.emplace_back(root);
        if_max(root->left, path, goodNode);
        if_max(root->right, path, goodNode);
    }   
};