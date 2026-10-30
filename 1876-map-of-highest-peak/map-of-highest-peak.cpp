class Solution {
public:
bool isValid(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>result(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={
            {0,1},{1,0},{0,-1},{-1,0}
        };
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto & it: dir){
                int newI=it[0]+i;
                int newJ=it[1]+j;

                if(isValid(newI,newJ,n,m) && result[newI][newJ]==-1){
                    result[newI][newJ]=result[i][j]+1;
                    q.push({newI,newJ});
                }
            }
        }
        return result;
    }
};