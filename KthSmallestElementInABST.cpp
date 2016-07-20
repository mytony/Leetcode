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
    int kthSmallest(TreeNode* root, int k) {
        int res, pos = 0;
        walk(root, k, pos, res);
        return res;
    }
    
    void walk(TreeNode* node, int k, int &pos, int &res) {
        // left subtree
        if (node->left) {
            walk(node->left, k, pos, res);
        }
        // count this node
        ++pos;
        if (pos == k) {
            res = node->val;
        }
        // right subtree
        if (node->right) {
            walk(node->right, k, pos, res);
        }
    }
};