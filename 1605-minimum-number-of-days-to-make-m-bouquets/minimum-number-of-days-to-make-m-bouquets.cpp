class Solution {
public:
bool canFit(vector<int>& bloomDay,int mid,int m,int k){
    int finalResult=0;
    int count=0;
    for(int it:bloomDay){
        if(it<=mid){
            count++;
            if(count==k){
                finalResult++;
                count=0;

                if(finalResult >=m){
                    return true;
                }
            }
        }
        else{
            count=0;
        }
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) k*m  > bloomDay.size()){
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canFit(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};