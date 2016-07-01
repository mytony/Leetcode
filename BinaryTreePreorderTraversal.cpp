/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Recursion
    // vector<int> res;
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if (root) {
    //         res.push_back(root->val);
    //         preorderTraversal(root->left);
    //         preorderTraversal(root->right);
    //     }
    //     return res;
    // }
    
    // Iteration
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        if (!root) return res;
        
        stack.push(root);
        while (!stack.empty()) {
            TreeNode *node = stack.top();
            stack.pop();
            res.push_back(node->val);
            if (node->right) {
                stack.push(node->right);
            }
            if (node->left) {
                stack.push(node->left);
            }
            
        }
        return res;
    }
};