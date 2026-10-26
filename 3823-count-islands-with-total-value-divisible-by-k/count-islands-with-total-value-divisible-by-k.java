class Solution {
    public long dfs(int i,int j,int[][] grid){
        int n=grid.length;
        int m=grid[0].length;
        long sum=0;

        if(i<0 || i>=n || j<0 || j>=m){
            return sum;
        }
        if(grid[i][j]==0){
            return sum;
        }
        sum+=grid[i][j];
        grid[i][j]=0;

        sum+=dfs(i-1,j,grid);
        sum+=dfs(i+1,j,grid);
        sum+=dfs(i,j-1,grid);
        sum+=dfs(i,j+1,grid);

        return sum;
    }
    public int countIslands(int[][] grid, int k) {
        int n=grid.length;
        int m=grid[0].length;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    long res=dfs(i,j,grid);
                    if(res%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
}