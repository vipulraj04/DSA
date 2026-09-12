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
    int height(TreeNode*root){
        if(root==nullptr){
            return 0;
        }

        int leftH=height(root->left);
        int rightH=height(root->right);

        return 1+max(leftH,rightH);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int leftD=diameterOfBinaryTree(root->left);
        int rightD=diameterOfBinaryTree(root->right);

        int combo=height(root->left)+height(root->right);

        return max({leftD,rightD,combo});
    }
};