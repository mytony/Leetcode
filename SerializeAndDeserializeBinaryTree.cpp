/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> queue;
        string str;
        if (!root) return str;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            if (node) {
                str += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            } else {
                str += "null,";
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        
        // get root value
        size_t startPos, dotPos;
        dotPos = data.find(',');
        TreeNode *root = new TreeNode(stoi(data.substr(0, dotPos)));
        queue<TreeNode*> queue;
        queue.push(root);
        
        // when pop(visit) a node, only assign left and right value
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            
            // left child
            startPos = dotPos+1;
            if (startPos == data.size()) break;
            dotPos = data.find(',', startPos);
            string val = data.substr(startPos, dotPos-startPos);
            if (val != "null") {
                node->left = new TreeNode(stoi(val));
                queue.push(node->left);
            }
            
            // right child
            startPos = dotPos+1;
            if (startPos == data.size()) break;
            dotPos = data.find(',', startPos);
            val = data.substr(startPos, dotPos-startPos);
            if (val != "null") {
                node->right = new TreeNode(stoi(val));
                queue.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));