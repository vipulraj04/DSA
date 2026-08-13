class Solution {
public:
bool isValid(int nr,int nc,int n,int m,vector<vector<int>>&grid,
vector<vector<int>>&dist){
    return (nr>=0 && nr < n && nc>=0 && nc < m && grid[nr][nc]==0 &&
    dist[nr][nc]==INT_MAX);
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};

        queue<pair<int,int>>q;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        q.push({0,0});
        dist[0][0]=1;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto & it : dir){
                int nr=i+it[0];
                int nc=j+it[1];

                if(isValid(nr,nc,n,m,grid,dist)){
                    dist[nr][nc]=dist[i][j]+1;
                    q.push({nr,nc});
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX){
            return -1;
        }

        return dist[n-1][m-1];
    }
};