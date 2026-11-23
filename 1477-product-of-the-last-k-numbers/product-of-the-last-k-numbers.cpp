class ProductOfNumbers {
    private:
    vector<int>arr;
public:
    ProductOfNumbers() {

    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int product=1;
        int n=arr.size();
        int j=n-1;
        while(k){
            product=product*arr[j];
            j--;
            k--;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */