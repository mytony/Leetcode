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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> nums;
        if (root) {
            walk(root, sum, res, nums, 0);
        }
        return res;
    }
    
    void walk(TreeNode* node, int sum, vector<vector<int>>& res, vector<int>& nums, int pathSum) {
        int newSum = pathSum + node->val;
        nums.push_back(node->val);
        
        // leaf node
        if (!node->left && !node->right && newSum == sum) {
            res.push_back(nums);
            nums.pop_back();
            return;
        }
        
        if (node->left) {
            walk(node->left, sum, res, nums, newSum);
        }
        if (node->right) {
            walk(node->right, sum, res, nums, newSum);
        }
        nums.pop_back();
    }
};