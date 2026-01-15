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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int index=0;
        return helper(preorder,inorder,index,0,inorder.size()-1);
    }

    TreeNode*helper(vector<int>& preorder, vector<int>& inorder,
    int &index,int left,int right){
        if(left > right){
            return nullptr;
        }

        int rootVal = preorder[index++];
        TreeNode*root=new TreeNode(rootVal);

        int pos=search(inorder,left,right,rootVal);

        root->left=helper(preorder,inorder,index,left,pos-1);
        root->right=helper(preorder,inorder,index,pos+1,right);

        return root;
    }

    int search(vector<int>& inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }

        return -1;
    }
};