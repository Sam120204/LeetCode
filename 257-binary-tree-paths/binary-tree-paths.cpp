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
    void addpaths(TreeNode* root, vector<string>& res, string cur_path, bool start) {
        if (!root) return;
        
        cur_path += start ? to_string(root->val) : "->" + to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(cur_path);
            return;
        }
        
        addpaths(root->left, res, cur_path, false);
        addpaths(root->right, res, cur_path, false);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res; 
        if (!root) return res;
        string cur_path = "";
        addpaths(root, res, cur_path, true);
        return res;
    }
};
