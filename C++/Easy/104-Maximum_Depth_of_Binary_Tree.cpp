// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode* root) {
        
        // Current node is null or after leaf node
        if(root == nullptr){
            return 0;
        }

        // When traversing back to the root node add 1 per level
        // once we return to the root node calculate the max for the 
        // left or right node
        if(root){
            return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
        }

        return 0;
    }
};