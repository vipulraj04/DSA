class Solution {
public:
bool helper(vector<int>&nums,int mid,int threshold){
    long long sum=0;
    for(int it: nums){
        sum+=it/mid;

        if(it%mid!=0){
            sum++;
        }
    }
    return sum <=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;

            if(helper(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};