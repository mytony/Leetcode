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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if (root) {
    //         postorderTraversal(root->left);
    //         postorderTraversal(root->right);
    //         res.push_back(root->val);
    //     }
    //     return res;
    // }
    
    // Iteration
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        unordered_set<TreeNode*> set;
        
        if (!root) return res;
        stack.push(root);
        
        while(!stack.empty()) {
            TreeNode *node = stack.top();
            if (set.find(node) == set.end()) {
                if (node->right) {
                    stack.push(node->right);
                }
                if (node->left) {
                    stack.push(node->left);
                }
                set.insert(node);
            } else {
                stack.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};