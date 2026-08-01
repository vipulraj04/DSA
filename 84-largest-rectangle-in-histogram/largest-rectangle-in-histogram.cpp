class Solution {
public:
vector<int>nse(vector<int>&nums){
    int n=nums.size();
    vector<int>result(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            result[i]=st.top();
        }
        else{
            result[i]=n;
        }
        st.push(i);
    }
    return result;
}
vector<int>pse(vector<int>&nums){
    int n=nums.size();
    vector<int>result(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            result[i]=st.top();
        }
        else{
            result[i]=-1;
        }
        st.push(i);
    }
    return result;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=pse(heights);
        vector<int>right=nse(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int width=right[i]-left[i]-1;
            int area=heights[i]*width;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};