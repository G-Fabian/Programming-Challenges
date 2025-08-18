// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

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
    int minDepth(TreeNode* root) {
        
        stack<pair<TreeNode*, int>> myStack; // node + depth
        
        // basecase: root is null
        if(!root){ return 0; }
        myStack.push({root,1});
        
        int minDepthVal = INT_MAX;
        while(!myStack.empty()){

            auto [node, depth] = myStack.top();
            myStack.pop();

         
             if (!node->left && !node->right){
                minDepthVal = min(minDepthVal, depth);
            }

            if(node->left != nullptr){
                myStack.push({node->left, depth + 1});
            }

            if(node->right != nullptr){
               myStack.push({node->right, depth + 1});
            }

        }

        return minDepthVal;
    }
};