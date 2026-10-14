class Solution {
    public int helper(int i,int j,int[][]nums,int [][] dp){
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

        dp[i][j]=top+down;

        return dp[i][j];
    }
    public int uniquePathsWithObstacles(int[][] nums) {
        int n=nums.length;
        int m=nums[0].length;

        int [][]dp=new int[n][m];

        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    int top=0;
                    int down=0;
                    if(i>0){
                        top=dp[i-1][j];
                    }
                    if(j>0){
                        down=dp[i][j-1];
                    }
                    dp[i][j]=top+down;
                }
            }
        }

        return dp[n-1][m-1];
    }
}