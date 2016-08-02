/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// looked forum
// https://discuss.leetcode.com/topic/8410/divide-and-conquer-f-i-g-i-1-g-n-i
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateSubtrees(1, n);
    }
private:
    vector<TreeNode*> generateSubtrees(int s, int e) {
        vector<TreeNode*> res;
        if (s > e) {
            res.push_back(NULL); // adding this is important
            return res;
        }
        
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> leftSubtrees = generateSubtrees(s, i - 1);
            vector<TreeNode*> rightSubtrees = generateSubtrees(i + 1, e);
            
            for (auto left: leftSubtrees) {
                for (auto right: rightSubtrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};