class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        int index=0;
        helper(nums,result,index);
        return result;
    }
    void helper(vector<int>& nums,vector<vector<int>>&result,int index){
        if(index>=nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            helper(nums,result,index+1);

            swap(nums[index],nums[i]);
        }
    }
};