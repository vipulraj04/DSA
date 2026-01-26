class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int minDiff=INT_MAX;
        for(int i=0;i<n-1;i++){
            int diff=arr[i+1]-arr[i];

            minDiff=min(minDiff,diff);
        }

        vector<vector<int>>result;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==minDiff){
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
        
    }
};