class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        vector<vector<int>>result;

        int minDiff=INT_MAX;

        for(int i=1;i<n;i++){
            int diff=arr[i]-arr[i-1];

            if(minDiff > diff){
                result.clear();
                minDiff=diff;

                result.push_back({arr[i-1],arr[i]});
            }

            else if(minDiff==diff){
                result.push_back({arr[i-1],arr[i]});
            }
        }

        return result;        
    }
};