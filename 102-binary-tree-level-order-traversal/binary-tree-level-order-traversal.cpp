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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res = {};
        queue<TreeNode*> q;
        q.push(root);
        int len = 1;
        while (q.size()) {
            vector<int> bfs = {};
            len = q.size();
            
            for (int i = 0; i < len; i++) {
                TreeNode* front = q.front();
                q.pop();
                bfs.emplace_back(front->val);
                if (front->left) {
                    q.push(front->left);
                } 
                if (front->right) {
                    q.push(front->right);
                }
            }
            res.emplace_back(bfs);
        }
        
        return res;
    }
};