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
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans="";
        ans+=to_string(root->val);
        vector<string>result;

        construct(root,ans,result);
        return result;
        
    }

    void construct(TreeNode*root,string ans, vector<string>&result){
        if(root->left==nullptr && root->right==nullptr){
            result.push_back(ans);
            return;
        }

        if(root->left){
            construct(root->left,ans + "->" +to_string(root->left->val),result);
        }
        if (root->right){
            construct(root->right,ans + "->" +to_string(root->right->val),result);
        }
    }
};