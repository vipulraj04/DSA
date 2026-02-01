class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int first = nums[0];
        int firstSmallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < firstSmallest) {
                secondSmallest = firstSmallest;
                firstSmallest = nums[i];
            }
            else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }

        return first + firstSmallest + secondSmallest;
    }
};
