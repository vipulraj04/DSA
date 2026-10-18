class Solution {
    boolean isValid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j < m;
    }
    public int[] lastVisitedCell(char[][] grid) {
        int n=grid.length;
        int m=grid[0].length;

        boolean [][] visited=new boolean[n][m];
        int i=0;
        int j=0;
        visited[i][j]=true;
        while(true){
            int ni=i;
            int nj=j;

            char ch=grid[i][j];

            if(ch=='L'){
                nj--;
            }
            else if(ch=='R'){
                nj++;
            }
            else if(ch=='U'){
                ni--;
            }
            else{
                ni++;
            }

            if(!isValid(ni,nj,n,m)){
                return new int[]{i,j};
            }
            if(visited[ni][nj]){
                return new int[]{i,j};
            }
            i=ni;
            j=nj;
            visited[i][j]=true;
        }
    }
}