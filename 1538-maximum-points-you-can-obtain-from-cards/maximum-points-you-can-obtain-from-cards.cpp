class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxSum=sum;
        int start=k-1;
        int end=n-1;
        while(start>=0){
            sum-=nums[start];
            start--;
            sum+=nums[end];
            end--;
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};