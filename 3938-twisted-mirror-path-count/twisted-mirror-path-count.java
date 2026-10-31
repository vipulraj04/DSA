class Solution {
    int mod=(int)1e9+7;
    public int helper(int i,int j,int dir,int [][][]dp,
    int [][] grid){
        int n=grid.length;
        int m=grid[0].length;

        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j][dir]!=-1){
            return dp[i][j][dir];
        }
        int res=0;
        if(grid[i][j]==0){
            res=(res+helper(i,j+1,0,dp,grid))%mod;
            res=(res+helper(i+1,j,1,dp,grid))%mod;
        }
        else{
            if(dir==0){
                res=helper(i+1,j,1,dp,grid);
            }
            else{
                res=helper(i,j+1,0,dp,grid);
            }
        }

        return dp[i][j][dir]=res%mod;
    }
    public int uniquePaths(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        int [][][]dp=new int[n][m][2];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }

        int right=helper(0,1,0,dp,grid);
        int left=helper(1,0,1,dp,grid);

        return (right+left) %mod;
    }
}