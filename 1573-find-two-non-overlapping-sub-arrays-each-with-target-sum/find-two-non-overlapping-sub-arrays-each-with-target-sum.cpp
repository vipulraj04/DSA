class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currSum=0;
        vector<int>getIdx(n,INT_MAX);

        int result=INT_MAX;
        int bestMin=INT_MAX;

        while(j<n){
            currSum+=arr[j];

            while(currSum > target){
                currSum-=arr[i];
                i++;
            }

            if(currSum==target){
                int len=j-i+1;
                if(i>0 && getIdx[i-1]!=INT_MAX){
                    result=min(result,len+getIdx[i-1]);
                }

                bestMin=min(bestMin,len);
            }

            getIdx[j]=bestMin;
            j++;
        }

        if(result==INT_MAX){
            return -1;
        }
        return result;
    }
};