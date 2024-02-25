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
        vector<vector<int>> ans; // We intialized a vector of vector ans to return
        if(root == NULL){ //If there's nothing return empty vector
            return ans;
        }

        queue<TreeNode*> q; // Initialized a Queue
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left!=NULL) {
                    q.push(node->left);
                }
                if(node->right!=NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);

            }
            ans.push_back(level);

        }
        return ans;
    }
};