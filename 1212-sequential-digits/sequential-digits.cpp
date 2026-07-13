class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        for(int i=1;i<9;i++){
            int newNumber=i;
            for(int j=i+1;j<10;j++){
                newNumber=newNumber*10+j;

                if(low <= newNumber && newNumber <= high){
                    result.push_back(newNumber);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};