class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int totalSum=0;
        for(int i=0;i<n;i++){
            int rev=122-s[i]+1;
            int pos=i+1;

            totalSum+=rev*pos;
        }

        return totalSum;
    }
};