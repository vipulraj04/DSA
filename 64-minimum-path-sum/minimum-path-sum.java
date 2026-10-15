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

        int [][] dp = new int[n][m];

        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    continue;
                }
                int top=Integer.MAX_VALUE;
                int down=Integer.MAX_VALUE;
                if(i>0){
                    top=dp[i-1][j];
                }
                if(j>0){
                    down=dp[i][j-1];
                }

                dp[i][j]=grid[i][j]+Math.min(top,down);
            }
        }

        return dp[n-1][m-1];
    }
}