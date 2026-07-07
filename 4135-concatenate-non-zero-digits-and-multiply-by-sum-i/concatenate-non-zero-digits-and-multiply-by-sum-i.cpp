class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long newNumber=0;
        string s= to_string(n);
        for(char c: s){
            int digit=c-'0';
            sum+=digit;
            if(digit >0){
                newNumber=newNumber*10+digit;
            }
        }

        return newNumber*sum;
    }
};