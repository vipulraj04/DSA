class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<long long>rowSum(n);
        vector<long long>colSum(m);

        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                total+=grid[i][j];

                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
        }
        if(total%2 !=0){
            return false;
        }

        long long rowS=0;
        for(int i=0;i<n-1;i++){
            rowS+=rowSum[i];

            if(rowS == total-rowS){
                return true;
            }
        }
        
        long long colS=0;
        for(int j=0;j<m-1;j++){
            colS+=colSum[j];

            if(colS==total-colS){
                return true;
            }
        }

        return false;
    }
};