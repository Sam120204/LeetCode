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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (sametree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
    bool sametree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return true;
        if (root and !subRoot || !root and subRoot) return false;
        if (root->val == subRoot->val) {
            if (sametree(root->left, subRoot->left) and sametree(root->right, subRoot->right)) return true;
        } else {
            return sametree(root->left, subRoot) and sametree(root->right, subRoot);
        }
        return false;
    }
    
};