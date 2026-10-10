class Solution {
    public int helper(int i,int j,int[][] nums,int[][]dp){
        if(i<0 || j<0){
            return 0;
        }
        if(nums[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int top=helper(i-1,j,nums,dp);
        int down=helper(i,j-1,nums,dp);

        dp[i][j]= top+down;
        return dp[i][j];
    }
    public int uniquePathsWithObstacles(int[][] nums) {
        int n=nums.length;
        int m=nums[0].length;

        int [][]dp=new int[n][m];
        for(int[] rows : dp){
            Arrays.fill(rows,-1);
        }
        return helper(n-1,m-1,nums,dp);
    }
}