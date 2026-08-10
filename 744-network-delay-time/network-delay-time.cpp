class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto & it : times){
            int u=it[0];
            int v=it[1];
            int c=it[2];

            adj[u].push_back({v,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto & it: adj[node]){
                int nNode=it.first;
                int ct=it.second;

                if(ct+weight < dist[nNode]){
                    dist[nNode]=ct+weight;
                    pq.push({ct+weight,nNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            else{
                ans=max(ans,dist[i]);
            }
        }
        return ans;
    }
};