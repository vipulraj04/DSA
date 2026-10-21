class Solution {
    public long helper(int i,int[]nums,boolean flag,long [][] dp){
        int n=nums.length;

        if(i>=n){
            return 0;
        }
        int state;
        if(flag){
            state=1;
        }
        else{
            state=0;
        }
        if(dp[i][state] !=-1){
            return dp[i][state];
        }
        long ntake=helper(i+1,nums,flag,dp);
        long val=nums[i];
        if(!flag){
            val=-val;
        }
        long take=helper(i+1,nums,!flag,dp)+val;

        return dp[i][state]=Math.max(ntake,take);
    }
    public long maxAlternatingSum(int[] nums) {
        int n=nums.length;
        long [][]dp=new long[n][2];
        for(long [] rows:dp){
            Arrays.fill(rows,-1);
        }

        return helper(0,nums,true,dp);
    }
}