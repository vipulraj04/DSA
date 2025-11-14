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
    bool isUnivalTree(TreeNode* root) {
        set<int>result;
        traversal(root,result);

        if(result.size()==1){
            return true;
        }

        return false;
    }

    void traversal(TreeNode*root,set<int>&result){
        if(root==nullptr){
            return;
        }
        traversal(root->left,result);
        result.insert(root->val);
        traversal(root->right,result);
    }
};