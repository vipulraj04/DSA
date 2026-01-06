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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int level=1;
        int ansLevel=1;
        int maxSum=INT_MIN;

        while(!q.empty()){
            int sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*top=q.front();
                q.pop();

                sum+=top->val;

                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }

            if(sum>maxSum){
                maxSum=sum;
                ansLevel=level;
            }
            level++;
        }

        return ansLevel;
    }
};