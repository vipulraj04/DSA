class Solution {
public:
    int binaryGap(int n) {
        int lastIndex=-1;
        int currIndex=0;
        int maxLen=0;
        while(n>0){
            if(n&1){
                if(lastIndex!=-1){
                    maxLen=max(maxLen,currIndex-lastIndex);
                }

                lastIndex=currIndex;
            }

            currIndex++;
            n>>=1;
        }

        return maxLen;
    }
};