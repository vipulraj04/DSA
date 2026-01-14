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
long long minVal;
long long secondVal;
    int findSecondMinimumValue(TreeNode* root) {

        minVal=LLONG_MAX;
        secondVal=LLONG_MAX;
        
        traversal(root);

        if(secondVal==LLONG_MAX){
            return -1;
        }
        else{
            return secondVal;
        }
    } 
    void traversal(TreeNode*root){
        if(root==nullptr){
            return;
        }
        if(root->val < minVal){
            secondVal=minVal;
            minVal=root->val;
        }
        else if(root->val > minVal && root->val < secondVal){
            secondVal=root->val;
        }
        traversal(root->left);
        traversal(root->right);
    }
};