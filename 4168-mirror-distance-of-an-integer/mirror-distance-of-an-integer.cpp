class Solution {
public:
    int mirrorDistance(int n) {

        int reversed=reverse(n);

        return abs(n-reversed);
        
    }
    int reverse(int n){
        int result=0;
        while(n>0){
            int rem=n%10;

            result=result*10+rem;
            n=n/10;
        }

        return result;
    }
};