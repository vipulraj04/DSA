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
        stack<TreeNode*>st;
        stack<int>stVal;

        st.push(root);
        stVal.push(root->val);
        while(!st.empty()){

            TreeNode*temp=st.top();
            st.pop();

            int temp2=stVal.top();
            stVal.pop();

            if(temp->left==nullptr && temp->right==nullptr && temp2==targetSum){
                return true;
            }

            if(temp->right){
                st.push(temp->right);
                stVal.push(temp2+temp->right->val);
            }
            if(temp->left){
                st.push(temp->left);
                stVal.push(temp2+temp->left->val);
            }
        }
        return false;
        
    }
};