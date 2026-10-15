class Solution {
    public int helper(int i,int j,int [][] grid,int [][] dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0 ){
            return Integer.MAX_VALUE;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int top=helper(i-1,j,grid,dp);
        int right=helper(i,j-1,grid,dp);

        dp[i][j]=grid[i][j]+Math.min(top,right);

        return dp[i][j];
    }
    public int minPathSum(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        int [][] dp=new int[n][m];
        for(int [] rows : dp){
            Arrays.fill(rows,-1);
        }

        return helper(n-1,m-1,grid,dp);
    }
}