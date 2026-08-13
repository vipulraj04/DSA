class Solution {
public:
bool isValid(int nr,int nc,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dist){
    return (nr>=0 && nc >=0 && nr < n && nc < m && grid[nr][nc]==0 && dist[nr][nc]==INT_MAX);
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{+1,+1},{-1,1},{1,-1}};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({1,{0,0}});

        while(!pq.empty()){
            int ct=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;

            pq.pop();

            for(auto & it : dir){
                int nr=i+it[0];
                int nc=j+it[1];

                if(isValid(nr,nc,n,m,grid,dist)){
                    if(ct  + 1 < dist[nr][nc]){
                        dist[nr][nc]= ct+1;
                        pq.push({ct+1,{nr,nc}});
                    } 
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX){
            return -1;
        }
        return dist[n-1][m-1];
    }
};