class Solution {
    public int helper(int idx,int [] coins,int amount,int[][] dp){
        if(idx==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return (int) 1e9;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int nTake=helper(idx-1,coins,amount,dp);
        int take=(int) 1e9;
        if(coins[idx]<=amount){
            take=1+helper(idx,coins,amount-coins[idx],dp);
        }

        return dp[idx][amount]=Math.min(take,nTake);
    }
    public int coinChange(int[] coins, int amount) {
        int n=coins.length;
        int [][]dp=new int[n][amount+1];
        for(int [] rows: dp){
            Arrays.fill(rows,-1);
        }
        int ans= helper(n-1,coins,amount,dp);
        if(ans==(int) 1e9){
            return -1;
        }
        return ans;
    }
}