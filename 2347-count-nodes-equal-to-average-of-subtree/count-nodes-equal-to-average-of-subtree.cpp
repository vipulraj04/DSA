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
pair<int,int>helper(TreeNode*root,int&result){
    if(root==nullptr){
        return {0,0};
    }
    auto leftCall=helper(root->left,result);
    auto rightCall=helper(root->right,result);

    int sum=leftCall.first+rightCall.first+root->val;
    int count=leftCall.second+rightCall.second+1;

    if(sum/count==root->val){
        result++;
    }

    return {sum,count};
}
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        helper(root,result);
        return result;
    }
};