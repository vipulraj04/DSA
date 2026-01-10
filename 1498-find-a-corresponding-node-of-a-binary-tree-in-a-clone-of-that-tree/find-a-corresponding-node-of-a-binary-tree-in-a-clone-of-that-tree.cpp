/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode*ans=nullptr;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        getTarget(cloned,target);
        return ans;
    }

    void getTarget(TreeNode*cloned,TreeNode*target){
        if(cloned==nullptr){
            return;
        }

        if(cloned->val==target->val){
            ans=cloned;
            return;
        }

        getTarget(cloned->left,target);
        getTarget(cloned->right,target);
    }
};