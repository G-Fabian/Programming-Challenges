// Given the root of a binary tree, invert the tree, and return its root

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr)
            return root;

        return switchNodes(root);
    }

    TreeNode* switchNodes(TreeNode* root){

        // Root must be a valid node cannot be null
        if(!root)
            return root;

        // Swap left and right child
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively traverse to the left and right nodes
        // to invert every left and right child node
        switchNodes(root->left);
        switchNodes(root->right);

        return root;
    }


};