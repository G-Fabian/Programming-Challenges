// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

// Return the merged tree.
// Note: The merging process must start from the root nodes of both trees.

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

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        // root1 is nullptr
        if(!root1)
            return root2;
        
        // root2 is nullptr
        if(!root2)
            return root1;

        // Both root1 and root2 are valid nodes so, merge them together  
        root1->val = root1->val + root2->val;
        
        // Recursively find and reassign root1's children (left and right node)
        root1->left  = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        // Return parent node
        return root1;
    }
};