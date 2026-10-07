class Solution {
public:
bool isValid(int i,int j,int n,int m){
    return i>=0 && j>=0 && i<n && j<m;
}
int helper(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    int count=1;
    visited[i][j]=true;

    if(isValid(i-1,j,n,m) && !visited[i-1][j] && grid[i-1][j]==1){
        count+=helper(i-1,j,visited,grid);
    }
    if(isValid(i+1,j,n,m) && !visited[i+1][j] && grid[i+1][j]==1){
        count+=helper(i+1,j,visited,grid);
    }
    if(isValid(i,j-1,n,m) && !visited[i][j-1] && grid[i][j-1]==1){
        count+=helper(i,j-1,visited,grid);
    }
    if(isValid(i,j+1,n,m) && !visited[i][j+1] && grid[i][j+1]==1){
        count+=helper(i,j+1,visited,grid);
    }

    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxAns=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int res=helper(i,j,visited,grid);

                    maxAns=max(maxAns,res);
                }
            }
        }
        return maxAns;
    }
};