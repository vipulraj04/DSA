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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return {};
        }
        return helper(1,n);
    }

    vector<TreeNode*>helper(int start,int end){
        if(start>end){
            return {nullptr};
        }

        vector<TreeNode*>result;
        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftBst=helper(start,i-1);
            vector<TreeNode*>rightBst=helper(i+1,end);

            for(TreeNode*left : leftBst){
                for(TreeNode*right :rightBst){
                    TreeNode*root= new TreeNode(i);

                    root->left=left;
                    root->right=right;

                    result.push_back(root);
                }
            }
        }
        return result;
    }
};