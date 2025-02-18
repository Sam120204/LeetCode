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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> layer;
        vector<int> res;
        layer.push(root);
        while (!layer.empty()) {
            int len = layer.size();
            for (int i = 0; i < len; i++) {
                auto node = layer.front();
                if (i == len-1) res.push_back(node->val);
                if (node->left) layer.push(node->left);
                if (node->right) layer.push(node->right); 
                layer.pop();
            }
        }
        return res;
    }
};