class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result=0;

        int maxIdx=-1;
        int minIdx=-1;
        int cIdx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK){
                cIdx=i;
            }

            if(nums[i]==minK){
                minIdx=i;
            }
            if(nums[i]==maxK){
                maxIdx=i;
            }

            long long smallerOne=min(minIdx,maxIdx);
            long long curr=smallerOne-cIdx;

            if(curr <=0){
                result+=0;
            }
            else{
                result+=curr;
            }
        }
        return result;
    }
};