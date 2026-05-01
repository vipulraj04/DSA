class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>result(n+1,0);
        for(int i=1;i<=n;i++){
            result[i]=result[i-1]+gain[i-1];
        }

        sort(result.begin(),result.end());

        return result[n];
    }
};