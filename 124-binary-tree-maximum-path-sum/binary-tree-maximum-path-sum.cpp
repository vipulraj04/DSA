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
int helper(TreeNode*root,int &maxSum){
    if(root==nullptr){
        return 0;
    }
    int l=helper(root->left,maxSum);
    int r=helper(root->right,maxSum);

    int midVal=l+r+root->val;
    int rootD=root->val;
    int mainVal=max(l,r)+root->val;

    maxSum=max({maxSum,midVal,rootD,mainVal});

    return max(rootD,mainVal);
}
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
    }
};