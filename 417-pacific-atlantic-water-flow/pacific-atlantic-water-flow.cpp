class Solution {
public:
bool isValid(int i,int j,vector<vector<int>>& heights){
    int n=heights.size();
    int m=heights[0].size();

    return i>=0 && j>=0 && i<n && j<m;
}
void dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& heights){
    visited[i][j]=true;
    if(isValid(i-1,j,heights) && !visited[i-1][j] && heights[i-1][j]>=heights[i][j]){
        dfs(i-1,j,visited,heights);
    }
    if(isValid(i+1,j,heights) && !visited[i+1][j] && heights[i+1][j]>=heights[i][j]){
        dfs(i+1,j,visited,heights);
    }
    if(isValid(i,j-1,heights) && !visited[i][j-1] && heights[i][j-1]>=heights[i][j]){
        dfs(i,j-1,visited,heights);
    }
    if(isValid(i,j+1,heights) && !visited[i][j+1] && heights[i][j+1]>=heights[i][j]){
        dfs(i,j+1,visited,heights);
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
         
        vector<vector<bool>>pVisited(n,vector<bool>(m,false));
        vector<vector<bool>>aVisited(n,vector<bool>(m,false));

        for(int j=0;j<m;j++){
            dfs(0,j,pVisited,heights);
            dfs(n-1,j,aVisited,heights);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,pVisited,heights);
            dfs(i,m-1,aVisited,heights);
        }
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pVisited[i][j] && aVisited[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};