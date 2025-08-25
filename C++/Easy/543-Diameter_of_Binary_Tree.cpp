// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

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
    
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        dfs(root, max_diameter);
        return max_diameter;
    }


    // Helper function to calulate the depth of a sub-tree
    int dfs(TreeNode* root, int &diameter){

        // Root either begins as null or beyond leaf node
        if(root == nullptr)
            return 0;
        
        // Calaculate the depth for children subtrees 
        int left  = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        // Update the current max diameter
        diameter = max(diameter, left+right);

        // Backtrack to parent node of current node increasing length
        // +1 counts for the current node and obtain the max depth from either child node
        return 1 + max(left,right);
    }


};