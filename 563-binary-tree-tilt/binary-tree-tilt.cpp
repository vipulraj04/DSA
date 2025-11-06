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
    int findTilt(TreeNode* root) {
        int totalSum=0;
        helper(root,totalSum);
        return totalSum;
    }
    int helper(TreeNode*root,int &totalSum){
        if(root==nullptr){
            return 0;
        }
        int lt=helper(root->left,totalSum);
        int rt=helper(root->right,totalSum);

        totalSum+=abs(lt-rt);

        return lt+rt+root->val;
    }
};