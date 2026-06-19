class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>result(n+1,0);
        result[0]=0;
        for(int i=1;i<=n;i++){
            result[i]=gain[i-1]+result[i-1];
        }

        return *max_element(result.begin(),result.end());
    }
};