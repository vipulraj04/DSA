class Solution {
public:
int getNum(vector<int>&nums,int k){
    int left=0;
    int n=nums.size();
    int count=0;
    unordered_map<int,int>mp;
    for(int right=0;right<n;right++){
        mp[nums[right]]++;

        while(mp.size() > k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                mp.erase(nums[left]);
            }
            left++;
        }
        count=count+(right-left+1);
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getNum(nums,k) - getNum(nums,k-1); 
    }
};