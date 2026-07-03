class Solution {
public:
bool isValid(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<vector<int>>result(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();

            result[i][j]=time;

            if(isValid(i+1,j,n,m) && !visited[i+1][j]){
                visited[i+1][j]=true;
                q.push({{i+1,j},time+1});
            }

            if(isValid(i-1,j,n,m) && !visited[i-1][j]){
                visited[i-1][j]=true;
                q.push({{i-1,j},time+1});
            }

            if(isValid(i,j+1,n,m) && !visited[i][j+1]){
                visited[i][j+1]=true;
                q.push({{i,j+1},time+1});
            }
            if(isValid(i,j-1,n,m) && !visited[i][j-1]){
                visited[i][j-1]=true;
                q.push({{i,j-1},time+1});
            }
        }

        return result;
    }
};