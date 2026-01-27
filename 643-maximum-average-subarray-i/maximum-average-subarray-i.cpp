class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum=0;
        for(int i=0;i<k;i++){
            maxSum+=nums[i];
        }
        double sum=maxSum;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];

            maxSum=max(sum,maxSum);
        }

        return maxSum/k;
    }
};