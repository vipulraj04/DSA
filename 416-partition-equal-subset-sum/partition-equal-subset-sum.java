class Solution {
    public boolean helper(int i,int []nums,int sum,Boolean[][] dp){
        if(sum==0){
            return true;
        }
        if(i==0){
            return nums[0]==sum;
        }
        if(dp[i][sum]!=null){
            return dp[i][sum];
        }

        boolean nTake=helper(i-1,nums,sum,dp);
        boolean take=false;
        if(sum >= nums[i]){
            take=helper(i-1,nums,sum-nums[i],dp);
        }

        return dp[i][sum]=nTake || take;
    }
    public boolean canPartition(int[] nums) {
        int sum=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum % 2!=0){
            return false;
        }
        int target=sum/2;

        Boolean [][] dp=new Boolean[n][target+1];

        return helper(n-1,nums,target,dp);
    }
}