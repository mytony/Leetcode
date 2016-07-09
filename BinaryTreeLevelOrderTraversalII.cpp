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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        
        queue.push(root);
        while (!queue.empty()) {
            vector<int> level;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                if (!node) continue;
                queue.push(node->left);
                queue.push(node->right);
                level.push_back(node->val);
            }
            if (level.size()) {
                res.insert(res.begin(), level);
            }
        }
        
        return res;
    }
};