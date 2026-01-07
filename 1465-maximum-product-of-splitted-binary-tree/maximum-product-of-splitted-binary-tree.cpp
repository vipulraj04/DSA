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
long long sum=0;
long long maxP=0;
const int mod=1e9+7;
    int maxProduct(TreeNode* root) {
        sum=totalsum(root);
        findPath(root);

       return maxP%mod;
    }

    long long totalsum(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        return root->val+totalsum(root->left)+totalsum(root->right);
    }

    long long findPath(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        long long left=findPath(root->left);
        long long right=findPath(root->right);

        long long totalSum=root->val+left+right;

        long long remainingSum=sum-totalSum;

        maxP=max(maxP,totalSum*remainingSum);

        return totalSum;
    }

};