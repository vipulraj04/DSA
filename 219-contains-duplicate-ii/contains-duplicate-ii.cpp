class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>result;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(result.count(nums[i])){
                return true;
            }

            result.insert(nums[i]);

            if(result.size()>k){
                result.erase(nums[i-k]);
            }
        }
        return false;
    }
};