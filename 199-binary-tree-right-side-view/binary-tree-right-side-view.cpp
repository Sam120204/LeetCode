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
        queue<TreeNode*> q;
        queue<TreeNode*> emptyQueue;
        q.push(root);
        vector<int> res;
        while (q.size()) {
            
            int levelSize = q.size(); // Number of nodes at the current level
            TreeNode* front = q.front();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* cur = q.front();
                if (cur->right) {
                    q.push(cur->right);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                q.pop();
            }
            res.emplace_back(front->val);
        }
        return res;
    }
};