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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return walk(root, sum, 0);
    }
    
    bool walk(TreeNode* node, int sum, int pathSum) {
        if (!node->left && !node->right) {
            return pathSum + node->val == sum ? true : false;
        }
        if (node->left) {
            bool res = walk(node->left, sum, pathSum + node->val);
            if (res) {
                return true;
            }
        }
        if (node->right) {
            bool res = walk(node->right, sum, pathSum + node->val);
            if (res) {
                return true;
            }
        }
        return false;
    }
};