class Solution {
public:
vector<int>getDigit(int n){
    vector<int>result;
    while(n){
        result.push_back(n%10);
        n=n/10;
    }
    return result;
}
    int maxProduct(int n) {
        vector<int>result=getDigit(n);
        int largest=-1;
        int secondLargest=-1;
        for(int it: result){
            if( it >= largest){
                secondLargest=largest;
                largest=it;
            }
            else if(it >= secondLargest){
                secondLargest=it;
            }
        }
        return largest*secondLargest;
    }
};