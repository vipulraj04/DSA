class Solution {
    public boolean isValid(int i,int j,int [][] grid){
        int n=grid.length;
        int m=grid[0].length;
        return i>=0 && j>=0 && i<n && j<m && grid[i][j]==1;
    }
    public int helper(int i,int j,boolean[][] visited,int[][] grid){
        int count=1;
        visited[i][j]=true;
        if(isValid(i-1,j,grid) && !visited[i-1][j]){
            count+=helper(i-1,j,visited,grid);
        }
        if(isValid(i+1,j,grid) && !visited[i+1][j]){
            count+=helper(i+1,j,visited,grid);
        }
        if(isValid(i,j-1,grid) && !visited[i][j-1]){
            count+=helper(i,j-1,visited,grid);
        }
        if(isValid(i,j+1,grid) && !visited[i][j+1]){
            count+=helper(i,j+1,visited,grid);
        }
        return count;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        boolean[][] visited=new boolean[n][m];
        int maxAns=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int res=helper(i,j,visited,grid);
                    maxAns=Math.max(maxAns,res);
                }
            }
        }
        return maxAns;
    }
}