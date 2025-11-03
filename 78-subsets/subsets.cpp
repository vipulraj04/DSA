class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        int index=0;

        helper(nums,result,ans,index);
        return result;
    }

    void helper(vector<int>& nums,vector<vector<int>>&result,vector<int>ans,int index){
        if(index>=nums.size()){
            result.push_back(ans);
            return;
        }

        helper(nums,result,ans,index+1);
        ans.push_back(nums[index]);
        helper(nums,result,ans,index+1);
    }
};