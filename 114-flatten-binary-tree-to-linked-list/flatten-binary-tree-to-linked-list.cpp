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
vector<TreeNode*>result;
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        traversal(root);

        TreeNode*temp=result[0];

        for(int i=1;i<=result.size()-1;i++){
            temp->left=nullptr;
            temp->right=result[i];
            temp=temp->right;
        }
        temp->left=nullptr;
        temp->right=nullptr;
        
    }
    void traversal(TreeNode*root){
        if(root==nullptr){
            return;
        }

        result.push_back(root);
        traversal(root->left);
        traversal(root->right);
    }
};