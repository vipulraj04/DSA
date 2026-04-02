class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            double w=succ[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<double>result(n,0.0);
        priority_queue<pair<double,int>>qp;

        result[start]=1.0;
        qp.push({1.0,start});

        while(!qp.empty()){
            double dis=qp.top().first;
            int node=qp.top().second;
            qp.pop();
            for(auto & ne : adj[node]){
                int neigh=ne.first;
                double wt=ne.second;

                double newW=dis*wt;
                if(newW> result[neigh]){
                    result[neigh]=newW;
                    qp.push({newW,neigh});
                }
            }
        }

        return result[end];
    }
};