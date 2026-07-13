class Solution {
public:
int getNum(vector<int>nums,int k){
    int sum=0;
    int left=0;
    int n=nums.size();
    int count=0;
    for(int right=0;right<n;right++){
        sum+=(nums[right]%2);
        while(sum > k){
            sum-=(nums[left]%2);
            left++;
        }
        count=count+(right-left+1);
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return getNum(nums,k) - getNum(nums,k-1);
    }
};