class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int n=nums.size();
        int minDiff=INT_MAX;

        sort(nums.begin(),nums.end());

        int i=0;
        int j=k-1;
        while(j<n){
            int maxE=nums[j];
            int minE=nums[i];

            int diff=maxE-minE;

            minDiff=min(minDiff,diff);

            i++;
            j++;
        }
        return minDiff;
    }
};