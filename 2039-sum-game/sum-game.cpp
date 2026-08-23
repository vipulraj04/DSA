class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftSum=0;
        int lqCount=0;
        for(int i=0;i< n/2;i++){
            if(num[i]=='?'){
                lqCount++;
            }
            else{
                leftSum+=num[i]-'0';
            }
        }
        int rightSum=0;
        int rqCount=0;
        for(int i=n/2;i<n;i++){
            if(num[i]=='?'){
                rqCount++;
            }
            else{
                rightSum+=num[i]-'0';
            }
        }
        int totalqMark=lqCount+rqCount;
        if(totalqMark %2 !=0){
            return true;
        }
        int qDiff=rqCount-lqCount;
        int sumDiff=leftSum-rightSum;

        return sumDiff !=9*qDiff/2;
    }
};