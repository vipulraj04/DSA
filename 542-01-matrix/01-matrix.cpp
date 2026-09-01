class Solution {
public:
bool isValid(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m );
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>result(n,vector<int>(m,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={
            {-1,0},{1,0},{0,-1},{0,1}
        };

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;

            q.pop();

            for(auto d: dir){
                int nx=i+d[0];
                int ny=j+d[1];

                if(isValid(nx,ny,n,m) && result[nx][ny]==-1){
                    result[nx][ny]=result[i][j]+1;
                    q.push({nx,ny});
                }
            }
        }

        return result;
    }
};