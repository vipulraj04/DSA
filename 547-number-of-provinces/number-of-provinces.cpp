class Solution {
public:
void dfs(int src,vector<int>&visited,vector<vector<int>>&result){
    visited[src]=1;
    for(auto it : result[src]){
        if(!visited[it]){
            dfs(it,visited,result);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<vector<int>>result(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] ==1){
                    result[i].push_back(j);
                    result[j].push_back(i);
                }
            }
        }

        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,result);
            }
        }
        return count;
    }
};