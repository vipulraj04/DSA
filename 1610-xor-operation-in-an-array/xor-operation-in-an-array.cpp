class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>result(n);
        int allZor=0;
        for(int i=0;i<n;i++){
            result[i]=start+2*i;

            allZor^=result[i];
        }

        return allZor;
    }
};