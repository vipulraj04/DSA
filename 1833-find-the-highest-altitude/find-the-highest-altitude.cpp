class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0;
        int maxResult=0;
        for(int i=0;i<gain.size();i++){
            curr+=gain[i];
            maxResult=max(maxResult,curr);
        }

        return maxResult;
    }
};