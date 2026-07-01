class Solution {
public:
bool canEat(vector<int>&piles,int mid,int h){
    long long total=0;
    for(int it:piles){
        total+=it/mid;
        if(it%mid!=0){
            total++;
        }
    }
    return total<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;

            if(canEat(piles,mid,h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};