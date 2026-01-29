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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<int>result;
        traversal(root,result);

        result.insert(lower_bound(result.begin(),result.end(),val),val);

        return newTree(result,0,result.size()-1);
    }
    void traversal(TreeNode*root,vector<int>&result){
        if(root==nullptr){
            return;
        }
        traversal(root->left,result);
        result.push_back(root->val);
        traversal(root->right,result);
    }

    TreeNode*newTree(vector<int>&result,int start,int end){
        if(start > end){
            return nullptr;
        }
        int mid=start+(end-start)/2;

        TreeNode*root=new TreeNode(result[mid]);

        root->left=newTree(result,start,mid-1);
        root->right=newTree(result,mid+1,end);

        return root;
    }
};