class Solution {
public:
    int elevatorRequests(int n, vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            result+=abs(nums[i]-nums[i-1]);
        }
        return result;
    }
};