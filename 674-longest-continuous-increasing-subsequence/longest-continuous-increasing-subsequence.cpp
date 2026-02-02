class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int maxCount=1;

        for(int i=1;i<n;i++){
            if(nums[i-1] < nums[i]){
                count++;

                maxCount=max(maxCount,count);
            }
            else{
                count=1;
            }
        }
        return maxCount;
        
    }
};