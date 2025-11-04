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
    vector<int> findMode(TreeNode* root) {
        vector<int>result;
        helper(root,result);

        unordered_map<int,int>answer;
        for(int val:result){
            answer[val]++;
        }
        int maxFreq=0;
        for(auto &p : answer){
            maxFreq=max(maxFreq,p.second);
        }

        vector<int>vipul;
        for(auto&p : answer){
            if(maxFreq==p.second){
                vipul.push_back(p.first);
            }
        }
        return vipul;

    }

    void helper(TreeNode*root,vector<int>&result){
        if(root==nullptr){
            return;
        }
        helper(root->left,result);
        result.push_back(root->val);
        helper(root->right,result);
    }
};