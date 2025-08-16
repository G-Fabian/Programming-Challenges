// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual 
// answer will be accepted.

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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;
        if(!root){ return result;} // Basecase: nullptr @ root
        
        // Utlizing queue to temp store nodes visited
        queue<TreeNode*> q;

        // Start BFS with root in queue
        q.push(root);
           
        while(!q.empty()){

            double sum=0;
            int n = q.size();

            // Sum the node values contained in each level 
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop(); // Remove front node from queue

                // Add current node value
                sum += node->val;

                // Left child node found put in queue
                if(node->left){
                    q.push(node->left);
                }

                // Right child node found put in queue
                if(node->right){
                    q.push(node->right);
                }
            }
            
            // Calculate the average of current level
            result.push_back(sum/n);
        }

        // Complete! send back results
        return result;    
    }


};