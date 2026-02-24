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
int helper(TreeNode*root,int total){
    if(root==nullptr){
        return 0;
    }

    total=(total*2)+root->val;
    if(root->left==nullptr && root->right==nullptr){
        return total;
    }
    return helper(root->left,total)+helper(root->right,total);
}
    int sumRootToLeaf(TreeNode* root) {
        return helper(root,0);
    }
};