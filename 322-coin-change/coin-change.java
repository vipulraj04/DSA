class Solution {
    public int helper(int[]coins,int amount,int[]dp){
        int n=coins.length;
        if(amount==0){
            return 0;
        }
        if(amount < 0){
            return Integer.MAX_VALUE;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int result=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            int ans=helper(coins,amount-coins[i],dp);
            if(ans!=Integer.MAX_VALUE){
                result=Math.min(ans+1,result);
            }
        }
        dp[amount]=result;

        return result;
    }
    public int coinChange(int[] coins, int amount) {
        int n=coins.length;
        int []dp=new int[amount+1];
        Arrays.fill(dp,-1);
        int res=helper(coins,amount,dp);
        if (res == Integer.MAX_VALUE) {
            return -1;
        }
        return res;
    }
}