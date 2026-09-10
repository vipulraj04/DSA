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
int helper(TreeNode*root,int &count){
    if(root==nullptr){
        return 0;
    }
    count++;
    int leftSum=helper(root->left,count);
    int rightSum=helper(root->right,count);

    return leftSum+rightSum+root->val;
}
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        if(root==nullptr){
            return 0;
        }
        int count=0;
        int sum=helper(root,count);

        if(sum/count == root->val){
            result++;
        }
        result+=averageOfSubtree(root->left);
        result+=averageOfSubtree(root->right);


        return result;
    }
};