class Solution {
public:
void Floyd(vector<vector<int>>&adj){
    int n=adj.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX){
                    adj[i][j]=min(adj[i][j],(adj[i][k]+ adj[k][j]));
                }
            }
        }
    }
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(auto & it: edges){
            int u=it[0];
            int v=it[1];
            int ct=it[2];

            adj[u][v]=ct;
            adj[v][u]=ct;
        }
        Floyd(adj);
        int cityCount=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(adj[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <=cityCount){
                cityCount=count;
                city=i;
            }
        }
        return city;
    }
};