class Solution {
public:
vector<int>nextSmaller(vector<int>&arr){
    int n=arr.size();
    vector<int>result(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
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
vector<int>previousSmaller(vector<int>&arr){
    int n=arr.size();
    vector<int>result(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            result[i]=st.top();
        }
        st.push(i);
    }
    return result;
}
    int sumSubarrayMins(vector<int>& arr) {
        const int mod=1e9+7;
        vector<int>NSE=nextSmaller(arr);
        vector<int>PSE=previousSmaller(arr);

        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int right=NSE[i]-i;
            int left=i-PSE[i];

            long long freq=(right*left*1ll);

            long long val=(freq*arr[i]*1ll)%mod;

            sum = (sum+val)%mod;
        }
        return sum;
    }
};