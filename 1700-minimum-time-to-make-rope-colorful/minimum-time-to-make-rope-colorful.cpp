class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int sumTotal=0;
        for(int i=1;i<n;i++){
            if(colors[i-1]==colors[i]){
                sumTotal+=min(neededTime[i],neededTime[i-1]);
                neededTime[i]=max(neededTime[i-1],neededTime[i]);
            }
        }
        return sumTotal;
        
    }
};