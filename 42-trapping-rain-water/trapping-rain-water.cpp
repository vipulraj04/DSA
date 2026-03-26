class Solution {
public:
vector<int>getLeft(vector<int>&height,int n){
    vector<int>result(n);
    result[0]=height[0];
    for(int i=1;i<n;i++){
        result[i]=max(result[i-1],height[i]);
    }
    return result;
}
vector<int>getRight(vector<int>&height,int n){
    vector<int>result(n);
    result[n-1]=height[n-1];

    for(int i=n-2;i>=0;i--){
        result[i]=max(result[i+1],height[i]);
    }
    return result;
}
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>left=getLeft(height,n);
        vector<int>right=getRight(height,n);

        int total=0;
        for(int i=0;i<n;i++){
            total+=min(left[i],right[i])-height[i];
        }
        return total;
    }
};