class Solution {
public:
    int reverseBits(int n) {
        unsigned long long result=0;
        for(int i=0;i<32;i++){
            long long lastBit=n%2;

            result=result*2+lastBit;

            n=n/2;
        }

        return (int)result;
        
    }
};