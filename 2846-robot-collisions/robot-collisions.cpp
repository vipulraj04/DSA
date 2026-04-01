class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& position, vector<int>& health, string direction) {
        int n=position.size();
        vector<int>index(n);
        for(int i=0;i<n;i++){
            index[i]=i;
        }

        auto lambda=[&](int a,int b){
            return position[a]<position[b];
        };
        sort(begin(index),end(index),lambda);

        stack<int>st;
        for(int i: index){
            if(direction[i]=='R'){
                st.push(i);
            }
            else{
                while(!st.empty() && health[i]>0){
                    int j=st.top();
                    if(health[i]>health[j])
                    {
                        st.pop();
                        health[i]--;
                        health[j]=0;
                    }
                    else if(health[i]<health[j]){
                        health[j]--;
                        health[i]=0;
                    }
                    else{
                        st.pop();
                        health[i]=0;
                        health[j]=0;
                    }
                }
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(health[i]!=0){
                result.push_back(health[i]);
            }
        }

        return result;
    }
};