class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int allZor=0;

        for(int i=0;i<=n;i++){
            allZor^=i;
        }

        for(int num : nums){
            allZor^=num;
        }
        
        return allZor;
    }
};