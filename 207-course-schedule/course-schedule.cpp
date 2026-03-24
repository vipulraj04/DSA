class Solution {
public:
bool isCycle(int src, vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&rec){
    visited[src]=true;
    rec[src]=true;

    for(int n : adj[src]){
        if(!visited[n]){
            if(isCycle(n,adj,visited,rec)){
                return true;
            }
        }
        else if(rec[n]){
            return true;
        }
    }

    rec[src]=false;
    return false;
}
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto & e: edges){
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        vector<bool>rec(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycle(i,adj,visited,rec)){
                    return false;
                }
            }
        }

        return true;

    }

};