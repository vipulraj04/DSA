class Solution {
public:
bool dfs(int src,vector<vector<int>>& adj,vector<bool>&visited,stack<int>&st,vector<bool>&recu){
    visited[src]=true;
    recu[src]=true;
    for(int n : adj[src]){
        if(!visited[n]){
            if(dfs(n,adj,visited,st,recu)){
                return true;
            }
        }
        else if(recu[n]){
            return true;
        }
    }
    recu[src]=false;
    st.push(src);
    return false;
}
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto & e: edges){
            adj[e[1]].push_back(e[0]);
        }

        vector<bool>visited(n,false);
        vector<bool>recu(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,st,recu)){
                    return {};
                }
            }
        }

        vector<int>result;
        while(!st.empty()){
            int top=st.top();
            result.push_back(top);
            st.pop();
        }

        return result;
    }
};