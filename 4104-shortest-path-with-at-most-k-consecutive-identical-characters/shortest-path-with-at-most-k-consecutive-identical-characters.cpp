class Solution {
public:
using p=pair<pair<int,int>,int>;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto & it : edges){
            int u=it[0];
            int v=it[1];
            int ct=it[2];
            adj[u].push_back({v,ct});
        }
        vector<vector<int>>result(n,vector<int>(k+1,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        result[0][1]=0;
        pq.push({{0,0},1});
        while(!pq.empty()){
            int dist=pq.top().first.first;
            int nNode=pq.top().first.second;
            int count=pq.top().second;

           pq.pop();

            if(dist > result[nNode][count]){
                continue;
            }
            if(nNode==n-1){
                return dist;
            }

            for(auto & it : adj[nNode]){
                int node=it.first;
                int wt=it.second;

                int newCount=0;
                if(labels[node]==labels[nNode]){
                    newCount=count+1;
                }
                else{
                    newCount=1;
                }

                if(newCount > k){
                    continue;
                }
                int newDist=dist+wt;
                if(newDist < result[node][newCount]){
                    result[node][newCount]=newDist;

                    pq.push({{newDist,node},newCount});
                }
            }
        }
        return -1;
    }
};