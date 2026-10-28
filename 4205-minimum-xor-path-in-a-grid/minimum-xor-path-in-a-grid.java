class Solution {
    public void helper(int i,int j,int zor,int n,int m,int [][] grid,
    boolean[][][]dp,int[]res){
        zor=zor^grid[i][j];

        if(res[0]==0){
            return ;
        }
        if(dp[i][j][zor]){
            return;
        }
        dp[i][j][zor]=true;

        if(i==n-1 && j==m-1){
            res[0]=Math.min(res[0],zor);
        }
        if(i+1<n){
            helper(i+1,j,zor,n,m,grid,dp,res);
        }
        if(j+1<m){
            helper(i,j+1,zor,n,m,grid,dp,res);
        }
    }
    public int minCost(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int[]res={Integer.MAX_VALUE};
        boolean [][][] dp=new boolean[n][m][1024];

        helper(0,0,0,n,m,grid,dp,res);

        return res[0];
    }
}