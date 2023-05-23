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
    int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        int height = findLenghtOfBT(root);
        return diameter;
    }
    
    int findLenghtOfBT(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftHeight = findLenghtOfBT(root->left);
        int rightHeight = findLenghtOfBT(root->right);
        
        diameter = max(diameter, leftHeight+rightHeight);
        
        return max(leftHeight,rightHeight)+1;
    }
};