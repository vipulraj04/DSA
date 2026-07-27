class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int x=nums[n-1];
        int y=nums[n-2];

        return (x-1) * (y-1);
    }
};