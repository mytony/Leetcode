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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        walk(root, sum, 0);
        return sum;
    }
    
    void walk(TreeNode* node, int &sum, int num) {
        num = num * 10 + node->val;
        // leaf node, a number forms
        if (!node->left && !node->right) {
            sum += num;
            return;
        }
        if (node->left) {
            walk(node->left, sum, num);
        }
        if (node->right) {
            walk(node->right, sum, num);
        }
    }
};