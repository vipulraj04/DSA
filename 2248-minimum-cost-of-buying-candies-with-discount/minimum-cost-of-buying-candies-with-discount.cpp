class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int count=0;
        int result=0;
        for(int i=n-1;i>=0;i--){
            if(count < 2){
                result+=cost[i];
                count++;
            }
            else{
                count=0;
            }
        }
        return result;
    }
};