class Solution {
public:
unordered_map<int,vector<vector<int>>>direction={
    {1,{{0,-1},{0,1}}},
    {2,{{1,0},{-1,0}}},
    {3,{{0,-1},{1,0}}},
    {4,{{0,1},{1,0}}},
    {5,{{0,-1},{-1,0}}},
    {6,{{-1,0},{0,1}}},
};
bool dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    if(i == n-1 && j==m-1){
        return true;
    }
    visited[i][j]=true;

    for(auto & dir: direction[grid[i][j]]){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        if(new_i <0 || new_i >=n || new_j <0 || new_j >=m|| visited[new_i][new_j]){
            continue;
        }

        for(auto &dirback : direction[grid[new_i][new_j]]){
            if(new_i + dirback[0]==i && 
            new_j+dirback[1]==j){
                if(dfs(new_i,new_j,visited,grid)){
                    return true;
                }
            }
        }
    }
    return false;
}
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        return dfs(0,0,visited,grid);

    }
};