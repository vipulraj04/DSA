class Solution {
public:
int helper(int num){
    int sum=0;
    int mul=1;
    while(num){
        int digit=num%10;
        sum+=digit;
        mul*=digit;

        num=num/10;
    }

    return sum+mul;
}
    bool checkDivisibility(int n) {
        int div=helper(n);
        return n%div==0;
    }
};