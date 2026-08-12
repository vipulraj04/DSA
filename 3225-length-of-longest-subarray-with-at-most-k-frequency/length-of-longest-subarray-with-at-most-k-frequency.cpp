class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int right=0;
        int maxLeft=0;
        for(int left=0;left<nums.size();left++){
            mp[nums[left]]++;

            while(mp[nums[left]] > k){
                mp[nums[right]]--;
                right++;
            }
            maxLeft=max(maxLeft,left-right+1);
        }
        return maxLeft;
    }
};