/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Fail to use recursion to do DFS and report error at early time at the same time
// So I turned to use iteration --> hard to record the depth of node for preorder or inorder
// Try recursion again
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int d = getDepth(root);
        if (d == -1) {
            return false;
        } else {
            return true;
        }
    }
    
    // Return -1 if two subtrees are not balanced, 0 if the node is NULL
    int getDepth(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        if (left >= 0 && right >= 0 && abs(left - right) <= 1) {
            return 1 + max(left, right);
        } else {
            return -1;
        }
    }
};