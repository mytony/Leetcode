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
// https://discuss.leetcode.com/topic/39659/easy-understanding-solution-with-dfs/2
class Solution {
public:
    int rob(TreeNode* root) {
        // return visit(root, true, 0);
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    
    // Return value: first is the profit if rob this house, 
    //              second is the profit if not rob.
    vector<int> dfs(TreeNode* node) {
        vector<int> vals(2, 0);
        if (!node) return vals;
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        vals[0] = node->val + left[1] + right[1];
        vals[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return vals;
    }
    
    // TLE: calculate same value repeatedly
    // int visit(TreeNode* node, bool canBeRob, int sum) {
    //     if (node == NULL) {
    //         return 0;
    //     }
        
    //     if (canBeRob) {
    //         // choose max between rob or not rob
    //         return sum + max(node->val + 
    //                   visit(node->left, false, 0) + 
    //                   visit(node->right, false, 0),
    //                   visit(node->left, true, 0) + 
    //                   visit(node->right, true, 0));
    //     } else {
    //         return sum + visit(node->left, true, 0) + 
    //                   visit(node->right, true, 0);
    //     }
    // }
};