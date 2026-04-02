class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto & e : times){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>qp;
        vector<int>result(n+1,INT_MAX);

        result[k]=0;
        qp.push({0,k});
        while(!qp.empty()){
            int dis=qp.top().first;
            int node=qp.top().second;

            qp.pop();
            for(auto & ne : adj[node]){
                int neigh=ne.first;
                int wt=ne.second;

                if(wt+dis < result[neigh]){
                    result[neigh]=wt+dis;

                    qp.push({wt+dis,neigh});
                }
            }
        }

        int ans=0;
        for(int i=1;i<result.size();i++){
            if(result[i]==INT_MAX){
                return -1;
            }

            ans=max(ans,result[i]);
        }
        return ans;
    }
};