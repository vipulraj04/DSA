class Solution {
public:
bool isCycle(int src,vector<bool>&visited,vector<bool>&recu,
vector<vector<int>>& adj,vector<int>&check){
    visited[src]=true;
    recu[src]=true;
    check[src]=0;
    for(int ne : adj[src]){
        if(!visited[ne]){
            if(isCycle(ne,visited,recu,adj,check)){
                return true;
            }
        }
        else if(recu[ne]){
            return true;
        }
    }
    check[src]=1;
    recu[src]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>visited(n,false);
        vector<bool>recu(n,false);
        vector<int>result;
        vector<int>check(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                isCycle(i,visited,recu,adj,check);
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