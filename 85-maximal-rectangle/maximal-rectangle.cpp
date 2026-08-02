class Solution {
public:
int largestArea(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    int maxArea=0;
    for(int i=0;i<=n;i++){
        while(!st.empty() &&(i==n || nums[st.top()] >= nums[i])){
            int ele=nums[st.top()];
            st.pop();
            int nse=i;
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int result=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>tempArr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    tempArr[j]++;
                }
                else{
                    tempArr[j]=0;
                }
            }
            result=max(result,largestArea(tempArr));
        }
        return result;
    }
};