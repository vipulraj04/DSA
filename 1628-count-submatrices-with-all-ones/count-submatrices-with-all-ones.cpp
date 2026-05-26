class Solution {
public:
int helper(vector<int>&result){
    int curr=0;
    int total=0;
    for(int num : result){
        if(num==0){
            curr=0;
        }
        else{
            curr++;
        }

        total+=curr;
    }
    return total;

}
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>result(m,1);
            for(int j=i;j<n;j++){
                for(int col=0;col<m;col++){
                    result[col]=result[col]& mat[j][col];
                }

                ans+=helper(result);
            }
        }

        return ans;
    }
};