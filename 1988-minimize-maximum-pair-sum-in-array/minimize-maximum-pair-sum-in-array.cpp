class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int maxSum=INT_MIN;
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=0;
            sum=nums[i]+nums[j];

            maxSum=max(sum,maxSum);

            i++;
            j--;
        }

        return maxSum;
        
    }
};