/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// The solution is that finding the paths from root to p and q, 
// then comparing it to find LCA.
// There's another solution I remembered from Tina
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p || !q) return NULL;
        
        // to store paths to n1 and n2 from the root
        vector<TreeNode*> path1, path2;
     
        // Find paths from root to p and root to q. If either p or q
        // is not present, return -1
        if ( !findPath(root, path1, p) || !findPath(root, path2, q)) {
            return NULL;
        }
     
        // Compare the paths to get the first different value
        int i;
        for (i = 0; i < path1.size() && i < path2.size() ; i++)
            if (path1[i] != path2[i])
                break;
        return path1[i-1];
    }
private:
    // Finds the path from root node to given node of the tree, Stores the
    // path in a vector path[], returns true if path exists otherwise false
    bool findPath(TreeNode *root, vector<TreeNode*> &path, TreeNode* k)
    {
        // base case
        if (root == NULL) return false;
     
        // Store this node in path vector. The node will be removed if
        // not in path from root to k
        path.push_back(root);
     
        // See if the k is same as root's key
        if (root == k)
            return true;
     
        // Check if k is found in left or right sub-tree
        if ( findPath(root->left, path, k) ||
             findPath(root->right, path, k) )
            return true;
     
        // If not present in subtree rooted with root, remove root from
        // path[] and return false
        path.pop_back();
        return false;
    }
};