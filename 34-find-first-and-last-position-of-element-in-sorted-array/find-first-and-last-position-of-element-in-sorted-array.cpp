class Solution {
public:
int rightSearch(vector<int>& nums, int target){
    int n=nums.size();
    int left=0;
    int right=n-1;
    int first=-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(nums[mid]==target){
            first=mid;
            right=mid-1;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return first;
}
int leftSearch(vector<int>& nums, int target){
    int n=nums.size();
    int left=0,right=n-1,second=-1;

    while(left<=right){
        int mid=left+(right-left)/2;
    if(nums[mid]==target){
        second=mid;

        left=mid+1;
    }
    else if(nums[mid]<target){
        left=mid+1;
    }
    else{
        right=mid-1;
    }
    } 

    return second;
}
    vector<int> searchRange(vector<int>& nums, int target) {

        int first=rightSearch(nums,target);
        int second=leftSearch(nums,target);

        return {first,second};

        
    }
};