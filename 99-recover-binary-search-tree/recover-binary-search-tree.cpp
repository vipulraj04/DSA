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
    void recoverTree(TreeNode* root) {
        inorder(root);

        TreeNode*first=nullptr;
        TreeNode*second=nullptr;

        for(int i=0;i<result.size()-1;i++){
            if(result[i]->val > result[i+1]->val){

                if(!first)
                first=result[i];

                second=result[i+1];
            }
        }

        swap(first->val,second->val);
    }
    vector<TreeNode*>result;

    void inorder(TreeNode*root){
        if(!root){
            return;
        }

        inorder(root->left);
        result.push_back(root);
        inorder(root->right);
    }
};