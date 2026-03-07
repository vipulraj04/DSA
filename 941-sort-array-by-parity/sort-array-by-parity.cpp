class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int right=n-1;
        for(int left=0;left<right;){
            if(nums[left]%2==0){
                left++;
            }
            else{
                swap(nums[left],nums[right]);
                right--;
            }
        }
        return nums;
    }
};