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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr){
            return true;
        }
        if(root==nullptr){
            return false;
        }

        if(isIdentical(root,subRoot)){
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }

    bool isIdentical(TreeNode*l1,TreeNode*l2){
        if(l1==nullptr && l2==nullptr){
            return true;
        }
        if(l1==nullptr || l2==nullptr){
            return false;
        }

        if(l1->val!=l2->val){
            return false;
        }

       return isIdentical(l1->left,l2->left) && isIdentical(l1->right,l2->right);
    }
};