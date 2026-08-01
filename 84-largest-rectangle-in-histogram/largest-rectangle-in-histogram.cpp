class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || heights[st.top()]>= heights[i])){
                int ele=heights[st.top()];
                int nse=i;
                st.pop();
                int pse;
                if(st.empty()){
                    pse=-1;
                }
                else{
                    pse=st.top();
                }
                maxArea=max(maxArea,ele*(nse-pse-1));
            }
            st.push(i);
        }
        return maxArea;
    }
};