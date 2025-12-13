class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool>result(n+1,true);

        for(int i=2;i<n;i++){
            if(result[i]){
                count++;

                for(int j=i*2;j<n;j=j+i){
                    result[j]=false;
                }
            }
        }
        return count;
        
    }
};