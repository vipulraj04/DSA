class Solution {
public:
bool dfs(int src,vector<bool>&visited,vector<bool>&recuPath,vector<int>&check,vector<vector<int>>& graph){
    visited[src]=true;
    recuPath[src]=true;
    check[src]=0;
    for(int ne: graph[src]){
        if(!visited[ne]){
            if(dfs(ne,visited,recuPath,check,graph)){
                return true;
            }
        }
        else if(recuPath[ne]){
            return true;
        }
    }
    check[src]=1;
    recuPath[src]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<bool>recuPath(n,false);
        vector<int>check(n);
        vector<int>result;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,recuPath,check,graph);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1){
                result.push_back(i);
            }
        }
        return result;
    }
};