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
    bool isBalanced(TreeNode* root) {

        if(root==nullptr){
            return true;
        }
        if(isBalanced(root->left)==false){
            return false;
        }
        if(isBalanced(root->right)==false){
            return false;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        if(abs(leftHeight-rightHeight)>1){
            return false;
        }
        return true;
    }
    int height(TreeNode*root){
        if(root==nullptr){
            return 0;
        }

        int leftH=height(root->left);
        int rightH=height(root->right);

        return 1+max(leftH,rightH);
    }
};