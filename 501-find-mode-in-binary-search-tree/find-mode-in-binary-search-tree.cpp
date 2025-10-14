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
unordered_map<int,int>result;
    vector<int> findMode(TreeNode* root) {
        if(!root){
            return {};
        }
        dfs(root);
        int maxFreq=0;

        for(auto &p :result){
            maxFreq=max(maxFreq,p.second);
        }
        
        vector<int>temp;
        for(auto&p : result){
            if(p.second==maxFreq){
                temp.push_back(p.first);
            }
        }

        return temp;
    }
    void dfs(TreeNode*root){
        if(!root){
            return;
        }
        result[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
};