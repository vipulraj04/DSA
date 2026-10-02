class Solution {
    public int helper(int n,int[] nums,int[] dp){
        int maxAns=Integer.MIN_VALUE;
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick=nums[n]+helper(n-2,nums,dp);
        int nPick=0+helper(n-1,nums,dp);

        maxAns=Math.max(maxAns,Math.max(pick,nPick));
        dp[n]=maxAns;
        return dp[n];
    }
    public int rob(int[] nums) {
        int n=nums.length;
        int [] dp=new int[n+1];
        Arrays.fill(dp,-1);
        int res=helper(n-1,nums,dp);

        return res;
    }
}