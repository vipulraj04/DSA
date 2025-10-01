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
    int getMinimumDifference(TreeNode* root) {
        vector<int>result;
        inorder(root,result);
        int minDiff=INT_MAX;

        for(int i=1;i<result.size();i++){
            minDiff=min(minDiff,result[i]-result[i-1]);
        }
        return minDiff;
    }
    void inorder(TreeNode*root,vector<int>&result){
        if(root==nullptr){
            return;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
};