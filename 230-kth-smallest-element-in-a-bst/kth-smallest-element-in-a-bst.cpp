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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>result;
        inorder(root,result);

        if(k<=result.size()){
            return result[k-1];
        }
        return -1;
    }
    void inorder(TreeNode* root,vector<int>&result){
        if(root==nullptr){
            return;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
};