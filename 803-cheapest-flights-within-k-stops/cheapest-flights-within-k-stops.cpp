class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto & it : flights){
            int u=it[0];
            int v=it[1];
            int ct=it[2];

            adj[u].push_back({v,ct});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int wt=q.front().second.second;

            q.pop();

            if(stop > k){
                continue;
            }

            for(auto & it:adj[node]){
                int nNode=it.first;
                int ct=it.second;

                if(ct+wt < dist[nNode] && stop <=k){
                    dist[nNode]=ct+wt;
                    q.push({stop+1,{nNode,ct+wt}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};