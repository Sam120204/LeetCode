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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool if_balanced = true;
        get_height(root, if_balanced);
        return if_balanced;
    }

    int get_height(TreeNode* root, bool& if_balanced) {
        if (!root) return 0;
        if (!root->left and !root->right) return 0;
        int left = 0, right = 0;
        if (root->left) left = 1 + get_height(root->left, if_balanced);
        if (root->right) right = 1 + get_height(root->right, if_balanced);
        
        if (abs(right - left) > 1) {
            cout << left << endl;
            cout <<right << endl;
            if_balanced = false;
        }
        return max(left, right);
    }
};