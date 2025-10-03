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
    int countNodes(TreeNode* root) {
        int height1=rightDepth(root);
        int height2=leftDepth(root);

        if(height1==height2){
            return (int)pow(2,height1)-1;
        }
        else{
            return 1+ countNodes(root->left) + countNodes(root->right);
        }
    }
    int rightDepth(TreeNode*root){
        int count=0;
        while(root!=nullptr){
            count++;
            root=root->right;
        }
        return count;
    }
    int leftDepth(TreeNode*root){
        int count=0;
        while(root!=nullptr){
            count++;
            root=root->left;
        }
        return count;
    }
};