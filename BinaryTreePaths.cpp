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
    // Use recursion is easier to handle string backtracking
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) {
            return res;
        }
        string path = to_string(root->val);
        walk(root, res, path);
        return res;
    }
    
    void walk(TreeNode* node, vector<string>& res, string path) {
        if (!node->left && !node->right) {
            res.push_back(path);
        }
        string nextPath;
        if (node->left) {
            nextPath = path + "->" + to_string(node->left->val);
            walk(node->left, res, nextPath);
        }
        if (node->right) {
            nextPath = path + "->" + to_string(node->right->val);
            walk(node->right, res, nextPath);
        }
    }
};