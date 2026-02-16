class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
        int max=nums[0];
        for(int i=1;i<n;i++){
            if(max<nums[i]){
                max=nums[i];
                maxIndex=i;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]==max){
                continue;
            }
            if(nums[i]!=max && max < 2*nums[i]){
                return -1;
            }
        }
        return maxIndex;
    }
};