class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size();
        int m=discounts.size();
        double result=0;
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int k=min(n,m);
        for(int i=0;i<k;i++){
            result += prices[i] * (100.0 - discounts[i]) / 100.0;
        }

        for(int i=k; i<n;i++){
            result+=prices[i];
        }

        return result;
    }
};