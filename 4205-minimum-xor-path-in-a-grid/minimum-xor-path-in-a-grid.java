class Solution {
    public int helper(int i,int j,int xor,Boolean[][][]dp,int[][] grid){
        if(i<0 || j<0){
            return 0;
        } 
        if(i==0 && j==0){
            return xor==grid[0][0]?1:0;
        }
        if(dp[i][j][xor]!=null){
            return dp[i][j][xor]?1:0;
        }
        int newZor=xor^grid[i][j];
        int top=helper(i-1,j,newZor,dp,grid);
        int down=helper(i,j-1,newZor,dp,grid);

        int ans=Math.max(top,down);
        dp[i][j][xor]=(ans==1);

        return ans;
    }
    public int minCost(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        Boolean [][][] dp=new Boolean[n][m][1024];

        for(int zor=0;zor<1024;zor++){
            if(helper(n-1,m-1,zor,dp,grid)==1){
                return zor;
            }
        }
        return -1;
    }
}