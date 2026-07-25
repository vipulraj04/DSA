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
        int maxProduct=0;
        for(int i=0;i<result.size();i++){
            for(int j=i+1;j<result.size();j++){
                maxProduct = max(maxProduct, result[i] * result[j]);
            }
        }
        return maxProduct;
    }
};