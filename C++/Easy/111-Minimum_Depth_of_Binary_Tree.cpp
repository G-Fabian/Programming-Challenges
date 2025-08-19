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
        
        // Iterative DFS (with a stack)

        // stack will contain an element with both node and depth
        stack<pair<TreeNode*, int>> myStack;
        
        // basecase: root is null
        if(!root){ return 0; }

        // begin stack pushing root
        myStack.push({root,1});
        
        int minDepthVal = INT_MAX;

        // Push each child into stack and continuing
        // traversing until a node reaches null, then
        // pop stack element until no elements left in stack
        while(!myStack.empty()){

            pair<TreeNode*, int> p = myStack.top();
            myStack.pop();

            TreeNode* node = p.first;
            int depth = p.second;

            // Node with both children = nullptr
            if (!node->left && !node->right){
                minDepthVal = min(minDepthVal, depth);
            }

            // Continue exploring left & save depth
            if(node->left != nullptr){
                myStack.push({node->left, depth + 1});
            }

             // Continue exploring right & save depth
            if(node->right != nullptr){
               myStack.push({node->right, depth + 1});
            }

        }

        return minDepthVal;



        // // Recursive Solution
    
        // // basecase: root is null
        // if(root==nullptr)
        //     return 0;
        // // Traverse right if left child is null
        // if(root->left == nullptr)
        //     return minDepth(root->right)+1;
        // // Traverse left if left child is null
        // if(root->right == nullptr)
        //     return minDepth(root->left)+1;
        // // Parent has both children, expand both & return minimun depth
        // return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};