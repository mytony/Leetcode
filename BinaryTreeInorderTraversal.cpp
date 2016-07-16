/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // looked forum for iteration method
 // https://leetcode.com/discuss/10927/three-methods-to-solve-c
 // Below article mentions recursion is not ideal when tree is not balanced
 // http://articles.leetcode.com/binary-search-tree-in-order-traversal
class Solution {
public:
    // Recursion -> trivial
    // vector<int> res;
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if (root) {
    //         inorderTraversal(root->left);
    //         res.push_back(root->val);
    //         inorderTraversal(root->right);
    //     }
    //     return res;
    // }
    
    // Iteration
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> set;
        
        if (!root) return res;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            if (node->left && set.find(node) == set.end()) {
                stk.push(node->left);
                set.insert(node);
            } else {
                stk.pop();
                res.push_back(node->val);

                if (node->right) {
                    stk.push(node->right);
                }
            }
        }
        return res;
    }

};