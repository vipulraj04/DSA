class Solution {
public:
bool canFit(vector<int>&weights,int mid,int days){
    int totalDays=1;
    int cap=0;
    for(int it:weights){
        if(it+cap <=mid){
            cap+=it;
        }
        else{
            totalDays++;
            cap=it;
        }
    }

    return totalDays <=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        long long low=*max_element(weights.begin(),weights.end());
        long long sum=0;
        for(int it:weights){
            sum+=it;
        }
        long long high=sum;
        while(low<=high){
            long long mid=low+(high-low)/2;

            if(canFit(weights,mid,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};