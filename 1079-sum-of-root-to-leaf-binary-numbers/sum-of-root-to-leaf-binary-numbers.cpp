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
int total=0;
void helper(TreeNode*root,string path){
    if(root==nullptr){
        return ;
    }
    path+=to_string(root->val);

    if(root->left==nullptr && root->right==nullptr){
        int sum = stoi(path,0,2);
        total+=sum;
    }

    helper(root->left,path);
    helper(root->right,path);
}
    int sumRootToLeaf(TreeNode* root) {
        helper(root,"");

        return total;
    }
};