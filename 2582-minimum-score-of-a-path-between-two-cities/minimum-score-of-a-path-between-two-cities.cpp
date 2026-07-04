class Solution {
public:
int dfs(int src,vector<bool>&visited,vector<vector<pair<int,int>>>&adj){
    visited[src]=true;
    int result=INT_MAX;
    for(auto& it:adj[src]){
        int u=it.first;
        int dist=it.second;

        result=min(result,dist);

        if(!visited[u]){
            result=min(result,dfs(u,visited,adj));
        }
    }
    return result;
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>visited(n+1);
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto & it:roads){
            int u=it[0];
            int v=it[1];
            int ct=it[2];

            adj[u].push_back({v,ct});
            adj[v].push_back({u,ct});
        }

        return dfs(1,visited,adj);
    }
};