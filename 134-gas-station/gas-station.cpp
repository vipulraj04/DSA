class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;
        for(int it : gas){
            totalGas+=it;
        }
        for(int it:cost){
            totalCost+=it;
        }
        if(totalGas < totalCost){
            return -1;
        }
        int start=0;
        int currGas=0;
        for(int i=0;i<gas.size();i++){
            currGas=currGas+gas[i]-cost[i];

            if(currGas < 0){
                start=i+1;
                currGas=0;
            }
        }
        return start;
    }
};