class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int negative=binarySearch(nums,0);
        int positive= nums.size() - binarySearch(nums,1);
        return max(negative,positive);
        
    }

    int binarySearch(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int result=nums.size();

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                result=mid;
                high=mid-1;
            }
        }
        return result;
    }

};