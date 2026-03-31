class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x: asteroids){
            if(st.empty() || x>0){
                st.push(x);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(x)){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(x);
                }
                else if(st.top()==abs(x)){
                    st.pop();
                }
            }
        }

        vector<int>result(st.size());

        for(int i=st.size()-1;i>=0;i--){
            result[i]=st.top();
            st.pop();
        }

        return result;
    }
};