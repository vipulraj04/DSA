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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>v;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left && t->right)
                if((t->right->val == x && t->left->val == y) || (t->right->val == y && t->left->val == x)) 
                return false;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            int cnt=0;
            for(auto it : v)
            {
                if(it == x || it == y) cnt++;
            }
            if(cnt == 2) return true;
        }    
        return false;
    }
};