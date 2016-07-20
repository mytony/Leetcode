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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return NULL;
        }
        
        // There is at least one node, so we can create it with no worry
        TreeNode *root = new TreeNode(0);
        assign(nums, 0, n-1, root);
        return root;
    }
    
    void assign(vector<int>& nums, int start, int end, TreeNode *node) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        node->val = nums[mid];
        
        // create a subtree if there are elements on the left of middle element
        if (mid != start) {
            node->left = new TreeNode(0);
            assign(nums, start, mid-1, node->left);
        }
        // create a subtree if there are elements on the right of middle element
        if (mid != end) {
            node->right = new TreeNode(0);
            assign(nums, mid+1, end, node->right);
        }
    }
};