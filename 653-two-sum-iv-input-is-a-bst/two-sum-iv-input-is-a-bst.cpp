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
    bool findTarget(TreeNode* root, int k) {
        vector<int>result;
        inorder(result,root);
        int n=result.size();
        int i=0;
        int j=n-1;

        while(i<j){
            int sum=result[i]+result[j];

            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
    void inorder(vector<int>&result,TreeNode*root){
        if(root==nullptr){
            return;
        }
        inorder(result,root->left);
        result.push_back(root->val);
        inorder(result,root->right);
    }

};