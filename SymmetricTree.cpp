/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Do by BFS. Get each vector of nodes of every level.
// Then compare if each vector is symmetric.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int q_size = nodes.size();
            vector<TreeNode*> level (q_size);
            
            for (int i = 0; i < q_size; i++) {
                TreeNode* p = nodes.front();
                nodes.pop();
                level[i] = p;
                // push childs into queue
                if (p) {
                    nodes.push(p->left);
                    nodes.push(p->right);
                }
            }
            
            // check if nodes in this level are symmetric
            int i = 0, j = level.size() - 1;
            while (i <= j) {
                TreeNode *a = level[i], *b = level[j];
                if ((a && !b) || (!a && b)) {
                    return false;
                }
                if (a && (a->val != b->val)) {
                    return false;
                }
                i++; j--;
            }
        }
        return true;
    }
};