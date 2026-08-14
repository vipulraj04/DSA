class Solution {
public:
using p=pair<int,pair<int,int>>;
bool isValid(int nr,int nc,int n,int m){
    return (nr >=0 && nc >=0 && nr < n && nc < m);
}
    int minimumEffortPath(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int wt=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            if(i==n-1 && j==m-1){
                return dist[n-1][m-1];
            }

            for(auto & it : dir){
                int nr=i+it[0];
                int nc=j+it[1];

                if(isValid(nr,nc,n,m)){
                    int newWt=max(wt,abs(nums[i][j]-nums[nr][nc]));
                    if(newWt < dist[nr][nc]){
                        dist[nr][nc]=newWt;
                        pq.push({newWt,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};