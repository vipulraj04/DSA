class Solution {
    public int helper(int idx,int [] nums,int target,int [][] dp){
        if(idx==0){
            if(target==0 && nums[0]==0){
                return 2;
            }
            if(target==0 || nums[0]==target){
                return 1;
            }
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int nTake=helper(idx-1,nums,target,dp);
        int take=0;
        if(nums[idx] <= target){
            take=helper(idx-1,nums,target-nums[idx],dp);
        }
        return dp[idx][target]=nTake+take;
    }
    public int findTargetSumWays(int[] nums, int trg) {
        int totalSum=0;
        for(int x: nums){
            totalSum+=x;
        }
        if(totalSum -trg < 0 || (totalSum-trg)%2!=0){
            return 0;
        }
        int n=nums.length;
        int target=(totalSum-trg)/2;
        int [][] dp=new int[n][target+1];
        for(int [] rows : dp){
            Arrays.fill(rows,-1);
        }

        return helper(n-1,nums,target,dp);
    }
}