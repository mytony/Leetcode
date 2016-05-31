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
    // The vertical level for root is 0
    // It reduces -1 if go to left child, 1 for right
    // Uses map to record every element in each v-level
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> hm;
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;

        if (root == nullptr) return res;

        q.emplace(root, 0);
        hm[0].push_back(root->val);
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();
            if (node->left != nullptr) {
                q.emplace(node->left, col-1);
                hm[col-1].push_back(node->left->val);
            }
            if (node->right != nullptr) {
                q.emplace(node->right, col+1);
                hm[col+1].push_back(node->right->val);
            }
        }

        // for every v-level, push the vector into result
        for (auto list : hm) {
            res.push_back(list.second);
        }

        return res;
    }
};