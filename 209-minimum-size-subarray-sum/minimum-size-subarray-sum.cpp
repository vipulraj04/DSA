class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int left=0;
        int maxLen=INT_MAX;

        for(int right=0;right<n;right++){
            sum+=nums[right];

            while(sum>=target){
                maxLen=min(maxLen,right-left+1);
                sum-=nums[left];
                left++;
            }
        }

        if(maxLen==INT_MAX){
            return 0;
        }
        else{
            return maxLen;
        }
    }
};