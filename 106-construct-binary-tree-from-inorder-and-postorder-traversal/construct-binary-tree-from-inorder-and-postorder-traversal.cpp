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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        
        return helper(inorder,postorder,index,0,postorder.size()-1);
    }

    TreeNode*helper(vector<int>&inorder,vector<int>&postorder,
    int &index,int left,int right){
        if(left > right){
            return nullptr;
        }

        int rootVal=postorder[index--];
        TreeNode*root=new TreeNode(rootVal);
        int pos=search(inorder,right,left,rootVal);

        root->right=helper(inorder,postorder,index,pos+1,right);
        root->left=helper(inorder,postorder,index,left,pos-1);

        return root;

    }
    int search(vector<int>&inorder,int right,int left,int rootVal){
        for(int i=left;i<=right;i++){
            if(inorder[i]==rootVal){
                return i;
            }
        }
        return -1;
    }

};