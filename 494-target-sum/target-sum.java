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
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else if(nums[0]<=target){
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int nTake=dp[i-1][j];
                int take=0;
                if(nums[i] <=j){
                    take=dp[i-1][j-nums[i]];
                }

                dp[i][j]=take+nTake;
            }
        }

        return dp[n-1][target];
    }
}