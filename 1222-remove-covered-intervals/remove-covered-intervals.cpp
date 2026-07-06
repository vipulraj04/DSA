class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        vector<vector<int>>result;

        auto lambda=[](vector<int>&vec1,vector<int>&vec2){
            if(vec1[0]==vec2[0]){
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };
        sort(nums.begin(),nums.end(),lambda);

        result.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(result.back()[0] <=nums[i][1] && result.back()[1] >= nums[i][1]){
                continue;
            }
            result.push_back(nums[i]);
        }
        return result.size();
    }
};