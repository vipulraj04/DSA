class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>result;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result.push_back(grid[i][j]);
            }
        }

        sort(result.begin(),result.end());
        int mid=result.size()/2;

        int target=result[mid];
        int ops=0;
        for(int num : result){
            if(target% x != num%x){
                return -1;
            }
            else{
                ops+=abs(target-num)/x;
            }
        }

        return ops;
    }
};