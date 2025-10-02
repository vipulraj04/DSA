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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
        stack<TreeNode*>s;
        stack<int>sVal;

        s.push(root);
        sVal.push(root->val);

        while(!s.empty()){
            TreeNode*temp=s.top();
            s.pop();
            int val=sVal.top();
            sVal.pop();

            if(temp->left==nullptr && temp->right==nullptr && val==targetSum){
                return true;
            }

            if(temp->right!=nullptr){
                s.push(temp->right);
                sVal.push(val+temp->right->val);
            }
            if(temp->left!=nullptr){
                s.push(temp->left);
                sVal.push(val+temp->left->val);
            }
        }
        return false;
        
    }
};