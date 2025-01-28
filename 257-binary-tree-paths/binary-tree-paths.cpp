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
    void dfs(TreeNode* root, vector<string>& results, vector<int> temp) {
        if (!root) return;
        
        temp.push_back(root->val); // Correctly push the value

        if (!root->left && !root->right) { // Leaf node case
            string res;
            for (int i = 0; i < temp.size(); i++) {
                if (i != temp.size() - 1) {
                    res += to_string(temp[i]) + "->";
                } else {
                    res += to_string(temp[i]);
                }
            }
            results.push_back(res);
            return;
        }
        
        if (root->left) dfs(root->left, results, temp);  // Pass the copied temp
        if (root->right) dfs(root->right, results, temp); // Pass the copied temp
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        if (!root) return results;
        dfs(root, results, {});
        return results;
    }
};