class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit=(n&1);
        n>>=1;

        while(n>0){
            bit=!bit;

            if((n&1)!=bit){
                return false;
            }

            n>>=1;
        }

        return true;
    }
};