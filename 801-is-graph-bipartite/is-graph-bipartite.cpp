class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int ne: graph[node]){
                        if(color[ne]==-1){
                            color[ne]=!color[node];
                            q.push(ne);
                        }

                        else if(color[ne]==color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};