class Solution {
public:
vector<int> getDigit(int n){
    vector<int>result;
    while(n){
        result.push_back(n%10);
        n=n/10;
    }
    return result;
}
    long long sumAndMultiply(int n) {
        vector<int>result=getDigit(n);
        long long newNumber=0;
        long long sum=0;
        for(int i=result.size()-1;i>=0;i--){
            sum+=result[i];
            if(result[i]>0){
                newNumber=newNumber*10+result[i];
            }
        }
        return newNumber*sum;
    }
};