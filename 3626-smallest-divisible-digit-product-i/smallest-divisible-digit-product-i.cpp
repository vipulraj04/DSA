class Solution {
public:
int digitProduct(int n){
    int result=1;
    while(n){
        int digit=n%10;
        result*=digit;
        n=n/10;
    }
    return result;
}
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(digitProduct(i)%t ==0){
                return i;
            }
        }
        return -1;
    }
};