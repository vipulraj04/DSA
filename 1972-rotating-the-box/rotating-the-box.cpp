class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<char>>result(m,vector<char>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[j][i]=grid[i][j];
            }
        }

        for(vector<char>&row : result){
            reverse(row.begin(),row.end());
        }

        for(int j=0;j<n;j++){
            int rowCount=m-1;
            for(int i=m-1;i>=0;i--){
                if(result[i][j]=='*'){
                    rowCount=i-1;
                    continue;
                }
                if(result[i][j]=='#'){
                    result[i][j]='.';
                    result[rowCount][j]='#';
                    rowCount--;
                }
            }
        }
        return result;
    }
};