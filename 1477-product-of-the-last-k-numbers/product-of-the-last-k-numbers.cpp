class ProductOfNumbers {
private:
vector<int>result;
public:
    ProductOfNumbers() {
        result.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            result.clear();
            result.push_back(1);
            return;
        }
        result.push_back(result.back()*num);
    }
    
    int getProduct(int k) {
        int n=result.size();
        if(k>=n){
            return 0;
        }
        return result[n-1]/result[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */