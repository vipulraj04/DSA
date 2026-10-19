class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        
        int [][] dp=new int[n][m];
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }    

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int down=matrix[i][j]+dp[i-1][j];
                int dL=(int) 1e9;
                int dR=(int) 1e9;
                if(j-1 >=0)
                dL=matrix[i][j]+dp[i-1][j-1];

                if(j+1 < m)
                dR=matrix[i][j]+dp[i-1][j+1];

                dp[i][j]=Math.min(down,Math.min(dL,dR));
            }
        }    

        int res=Integer.MAX_VALUE;
        for(int j=0;j<m;j++){
            res=Math.min(res,dp[n-1][j]);
        }

        return res;

    }
}