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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int>result1;
        vector<int>result2;
        getLeaf(root1,result1);
        getLeaf(root2,result2);

        return result1==result2;
        
    }
    void getLeaf(TreeNode*root,vector<int>&result){
        if(!root){
            return;
        }

        if(root->left == nullptr && root->right==nullptr){
            result.push_back(root->val);
        }

        getLeaf(root->left,result);
        getLeaf(root->right,result);
    }
};