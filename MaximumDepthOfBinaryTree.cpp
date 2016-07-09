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
    int maxDepth(TreeNode* root) {
        return visit(root, 1);
    }
    
    int visit(TreeNode* node, int depth) {
        if (!node) {
            return 0;
        }
        // leaf
        if (!(node->left || node->right)) {
            return depth;
        }
        return max(visit(node->left, depth+1), visit(node->right, depth+1));
    }
};