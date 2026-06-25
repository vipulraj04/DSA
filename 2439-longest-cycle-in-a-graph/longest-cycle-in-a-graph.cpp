class Solution {
public:
int result=-1;
void dfs(int i, 
vector<bool>&visited,
vector<bool>&recu,
vector<int>&count,
vector<int>& edges){
    if(i!=-1){
        visited[i]=true;
        recu[i]=true;
        int v=edges[i];
        if(v!=-1){
        if(!visited[v]){
            count[v]=count[i]+1;
            dfs(v,visited,recu,count,edges);
        }
        else if(recu[v]){
            result=max(result,count[i]-count[v]+1);
        }
        }
        recu[i]=false;
    }
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<bool>recu(n,false);
        vector<int>count(n,1);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,recu,count,edges);
            }
        }
        return result;
    }
};