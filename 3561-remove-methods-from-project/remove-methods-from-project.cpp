class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<vector<int>>adj(n);
        vector<bool>sus(n,false);
        vector<int>in(n);
        for(auto &it : nums){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            in[v]++;
        }

        queue<int>q;
        q.push(k);
        sus[k]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(int it:adj[curr]){
                in[it]--;
                if(!sus[it]){
                    q.push(it);
                    sus[it]=true;
                }
            }
        }

        vector<int>result;
        bool canForm=false;
        for(int i=0;i<n;i++){
            if(sus[i] && in[i] >0){
                canForm=true;
                break;
            }

            if(!sus[i]){
                result.push_back(i);
            }
        }


        if(canForm){
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                ans[i]=i;
            }
            return ans;
        }
        return result;
    }
};