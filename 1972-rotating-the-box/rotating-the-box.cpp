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
            for(int i=m-1;i>=0;i--){
                if(result[i][j]=='.'){
                    int stoneRow=-1;

                    for(int k=i-1;k>=0;k--){
                        if(result[k][j]=='*'){
                            break;
                        }
                        else if(result[k][j]=='#'){
                            stoneRow=k;
                            break;
                        }
                    }

                    if(stoneRow!=-1){
                        result[i][j]='#';
                        result[stoneRow][j]='.';
                    }
                }
            }
        }
        return result;
    }
};