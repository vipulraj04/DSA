class Solution {
    public int longestOnes(int[] nums, int k) {
        int n=nums.length;
        int right=0;
        int maxLength=0;
        int zero=0;
        for(int left=0;left<n;left++){
            if(nums[left]==0){
                zero++;
            }
            while(zero >k){
                if(nums[right]==0){
                    zero--;
                }
                right++;
            }

            maxLength=Math.max(maxLength,left-right+1);
        }

        return maxLength;
    }
}