class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int result=x^y;

        while(result){
            if(result & 1){
                count++;
            }
            result >>=1;
        }
        return count;
        
    }
};